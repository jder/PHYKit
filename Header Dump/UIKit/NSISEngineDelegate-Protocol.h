/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import <Foundation/NSObject.h>
@protocol NSISEngineDelegate <NSObject>
- (void)engine:(id)arg1 willBreakConstraint:(id)arg2 dueToMutuallyExclusiveConstraints:(id)arg3;
- (id)engine:(id)arg1 markerForConstraintToBreakAmongConstraints:(id)arg2;
- (void)constraintsDidChangeInEngine:(id)arg1;
@end
