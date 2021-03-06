//
//  SnapViewController.m
//  Newton
//
//  Created by Zev Eisenberg on 8/2/13.
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

#import "SnapViewController.h"

@interface SnapViewController () <PHYViewDelegate>

@property (nonatomic, weak) IBOutlet PHYView *square1;
@property (nonatomic, strong) PHYDynamicAnimator *animator;
@property (nonatomic, strong) PHYSnapBehavior *snapBehavior;

@end

@implementation SnapViewController

- (void)awakeFromNib
{
    self.square1.backgroundColor = [NSColor grayColor];
    [(PHYView*)self.view setDelegate: self];

    self.animator = [[PHYDynamicAnimator alloc] initWithReferenceView:self.view];
}

- (void)viewClicked:(NSEvent *)theEvent
{
    NSPoint point = [self.view convertPoint:theEvent.locationInWindow fromView:nil];

    [self.animator removeBehavior: self.snapBehavior];

    self.snapBehavior = [[PHYSnapBehavior alloc] initWithItem:self.square1 snapToPoint:point];
    [self.animator addBehavior: self.snapBehavior];
}

@end
