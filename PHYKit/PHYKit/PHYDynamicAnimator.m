//
//  PHYDynamicAnimator.m
//  PHYKit
//
//  Created by Nathan Trapp on 6/19/13.
//
//

#import "PHYDynamicAnimator.h"
#import "PHYDynamicBehavior.h"
#import "PHYWorld.h"
#import "PHYBody.h"
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>


@interface PHYDynamicAnimator ()
{
    NSMutableArray *_behaviors;
    CVDisplayLinkRef _displayLink;
}

@property (nonatomic, strong) PHYWorld *world;

@property (nonatomic, strong) NSView *referenceView;
@property (nonatomic) NSTimeInterval elapsedTime;
@property (nonatomic, weak) NSThread *thread;
@property (nonatomic) NSTimeInterval startTime;
@property (nonatomic) NSTimeInterval lastTime;
@property (assign) BOOL isSimulating;
@end

@implementation PHYDynamicAnimator

static CVReturn displayLinkCallback(CVDisplayLinkRef displayLink, const CVTimeStamp* now, const CVTimeStamp* outputTime, CVOptionFlags flagsIn, CVOptionFlags* flagsOut, void* displayLinkContext)
{
    [(__bridge PHYDynamicAnimator*)displayLinkContext updatePhysics];
    
    return kCVReturnSuccess;
}

- (instancetype)initWithReferenceView:(NSView*)view
{
    if ((self = [super init]))
    {
        self.world = [[PHYWorld alloc] initWithReferenceView: view];
        self.referenceView = view;
        _behaviors = [NSMutableArray array];
        self.thread = [NSThread currentThread];
        
        
        CVDisplayLinkCreateWithActiveCGDisplays(&_displayLink);
        
        // Set the renderer output callback function
        CVDisplayLinkSetOutputCallback(_displayLink, &displayLinkCallback, (__bridge void*)self);
    }
    
    return self;
}

- (void)dealloc
{
    [self removeAllBehaviors];
    CVDisplayLinkStop(_displayLink);
    CVDisplayLinkRelease(_displayLink);
    _displayLink = NULL;
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    switch ((NSKeyValueChange)[[change objectForKey:@"kind"] unsignedIntegerValue]) {
        case NSKeyValueChangeRemoval:
        {
            PHYDynamicBehavior *behavior = (PHYDynamicBehavior*)object;
            NSArray *items = [behavior.items objectsAtIndexes:[change objectForKey:@"indexes"]];
            for (id<PHYDynamicItem> item in items)
            {
                [self.world removeBody: [self bodyFromDynamicItem: item]];
            }


            BOOL hasItems = NO;

            for (PHYDynamicBehavior *behavior in self.behaviors)
            {
                if ([behavior respondsToSelector:@selector(items)])
                {
                    if ([[(id)behavior items] count])
                    {
                        hasItems = YES;
                        break;
                    }
                }
            }

            if (!hasItems)
            {
                [self stopPhysics];
            }
        }
            break;

        case NSKeyValueChangeInsertion:
        {
            PHYDynamicBehavior *behavior = (PHYDynamicBehavior*)object;

            NSArray *items = [behavior.items objectsAtIndexes:[change objectForKey:@"indexes"]];
            for (id<PHYDynamicItem> item in items)
            {
                [self.world addBody: [[PHYBody alloc] initWithDynamicItem: item]];
            }

            [self startPhysics];
        }
            break;

        default:
            break;
    }
}

- (void)addBehavior:(PHYDynamicBehavior *)behavior
{
    [_behaviors addObject: behavior];

    [behavior addObserver:self forKeyPath:@"items" options:0 context:NULL];

    for (id<PHYDynamicItem> item in behavior.items)
    {
        if (![self bodyFromDynamicItem: item])
        {
            [self.world addBody: [[PHYBody alloc] initWithDynamicItem: item]];
        }
    }

    [behavior willMoveToAnimator: self];

    if ([_behaviors count])
    {
        [self startPhysics];
    }
}

- (void)removeBehavior:(PHYDynamicBehavior *)behavior
{    
    [_behaviors removeObject:behavior];

    [behavior removeObserver:self forKeyPath:@"items"];

    for (id<PHYDynamicItem> item in behavior.items)
    {
        [self.world removeBody: [self bodyFromDynamicItem: item]];
    }

    [behavior willMoveToAnimator: nil];

    if ([_behaviors count])
    {
        [self startPhysics];
    }
    else
    {
        [self stopPhysics];
    }
}

- (void)removeAllBehaviors
{
    for (PHYDynamicBehavior *behavior in _behaviors)
    {
        [behavior removeObserver:self forKeyPath:@"items"];
        [behavior willMoveToAnimator: nil];
    }

    [_behaviors removeAllObjects];
    [self.world removeAllBodies];
    
    [self stopPhysics];
}

- (NSArray*)itemsInRect:(CGRect)rect
{
    NSMutableArray *items = [NSMutableArray array];

    for (PHYDynamicBehavior *behavior in self.behaviors)
    {
        if ([behavior respondsToSelector:@selector(items)])
        {
            for (id <PHYDynamicItem> item in [(id)behavior items])
            {
#warning update this to use the transform to take rotation into account
                CGPoint itemCenter = item.center;
                CGRect itemBounds = NSRectToCGRect(item.bounds);

                CGRect itemRect = CGRectMake(itemCenter.x - CGRectGetWidth(itemBounds) / 2,
                                             itemCenter.y - CGRectGetHeight(itemBounds) / 2,
                                             itemBounds.size.width,
                                             itemBounds.size.height);

                if (CGRectIntersectsRect(rect, itemRect))
                {
                    [items addObject: item];
                }
            }
        }
    }
    
    return items;
}

- (void)updateItemUsingCurrentState:(id <PHYDynamicItem>)item
{
    [self.world removeBody: [self bodyFromDynamicItem: item]];
    [self.world addBody: [[PHYBody alloc] initWithDynamicItem: item]];
}

// starts when a new behavior or item is added
- (void)startPhysics
{
    if (!self.isSimulating)
    {
        self.isSimulating = YES;
        [self.delegate dynamicAnimatorWillResume:self];
        self.startTime = [NSDate timeIntervalSinceReferenceDate];
        self.lastTime = self.startTime - 1.0/60;

        CVDisplayLinkStart(_displayLink);
    }
}

// stops when we reach a state of rest or all behaviors and items are removed
- (void)stopPhysics
{
    if (self.isSimulating)
    {
        self.isSimulating = NO;
        CVDisplayLinkStop(_displayLink);
        [self.delegate dynamicAnimatorDidPause:self];
    }
}

- (void)updatePhysics
{
    @autoreleasepool
    {
        NSTimeInterval now = [NSDate timeIntervalSinceReferenceDate];

        [self.world stepWithTime:(now - self.lastTime)];

        self.lastTime = now;
        self.elapsedTime = self.lastTime - self.startTime;

        [self applyPostStepBlocks];
    }
}

- (void)applyPostStepBlocks
{
    for (PHYDynamicBehavior *behavior in _behaviors)
    {
        if (behavior.action)
        {
            behavior.action();
        }
    }
}

- (PHYBody*)bodyFromDynamicItem:(id <PHYDynamicItem>)dynamicItem
{
    for (PHYBody *body in [self.world bodies])
    {
        if ([body.dynamicItem isEqual: dynamicItem])
        {
            return body;
        }
    }

    return nil;
}

@end
