//
//  PHYView.h
//  PHYKit
//
//  Created by Nathan Trapp on 6/19/13.
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

#import <Foundation/Foundation.h>
#import "PHYDynamicBehavior.h"

@protocol PHYViewDelegate <NSObject>
@optional
- (void)viewClicked:(NSEvent*)event;
- (void)viewDragged:(NSEvent*)event;

@end

@interface PHYView : NSView <PHYDynamicItem>

@property (weak) id<PHYViewDelegate> delegate;

@property (nonatomic) CGAffineTransform transform;
@property (nonatomic) NSColor *backgroundColor;
@property (nonatomic) CGFloat alpha;

+ (void)animateWithDuration:(NSTimeInterval)duration
                 animations:(void (^)(void))animationBlock;
+ (void)animateWithDuration:(NSTimeInterval)duration
                 animations:(void (^)(void))animationBlock
                 completion:(void (^)(void))completionBlock;

@end