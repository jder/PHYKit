/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import <Foundation/NSObject.h>
NSCoding.h
@class NSString;

__attribute__((visibility("hidden")))
@interface UIProxyObject : NSObject <NSCoding>
{
    NSString *proxiedObjectIdentifier;
}

+ (void)removeMappingsForCoder:(id)arg1;
+ (id)mappedObjectForCoder:(id)arg1 withIdentifier:(id)arg2;
+ (void)addMappings:(id)arg1 forCoder:(id)arg2;
+ (void)addMappingFromIdentifier:(id)arg1 toObject:(id)arg2 forCoder:(id)arg3;
+ (struct __CFDictionary *)proxyDecodingMap;
- (id)proxiedObjectIdentifier;
- (void)setProxiedObjectIdentifier:(id)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end
