/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import <Foundation/NSObject.h>
@class CALayer, UIView, UIWebOverflowScrollView;

__attribute__((visibility("hidden")))
@interface UIWebOverflowScrollViewInfo : NSObject
{
    UIWebOverflowScrollView *_scrollView;
    CALayer *_scrollViewLayer;
    UIView *_oldSuperview;
}

@property(retain, nonatomic) UIView *oldSuperview; // @synthesize oldSuperview=_oldSuperview;
@property(retain, nonatomic) UIWebOverflowScrollView *scrollView; // @synthesize scrollView=_scrollView;
- (void)dealloc;
- (id)initWithScrollView:(id)arg1;

@end
