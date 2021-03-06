//
//  PHYContact.h
//  PHYKit
//
//  Created by Nathan Trapp on 7/27/13.
//  Copyright (c) 2013 Nathan Trapp and Zev Eisenberg. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/NSObject.h>
@class PHYBody;

@interface PHYContact : NSObject
{
    PHYBody *_bodyA;
    PHYBody *_bodyB;
    struct CGPoint _contactPoint;
    float _impulse;
    BOOL _didBegin;
    BOOL _didEnd;
}

- (id).cxx_construct;
- (void).cxx_destruct;
@property(readonly, nonatomic) float collisionImpulse;
@property(readonly, nonatomic) struct CGPoint contactPoint;
@property(readonly, nonatomic) PHYBody *bodyB;
@property(readonly, nonatomic) PHYBody *bodyA;
- (void)setCollisionImpulse:(float)arg1;
- (void)setBodyB:(id)arg1;
- (void)setBodyA:(id)arg1;
- (void)setContactPoint:(struct CGPoint)arg1;
@property BOOL didEnd;
@property BOOL didBegin;
- (id)init;

@end

