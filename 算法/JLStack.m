//
//  JLStack.m
//  算法
//
//  Created by Wangjianlong on 2020/12/26.
//  Copyright © 2020 wangjianlong. All rights reserved.
//

#import "JLStack.h"

@interface JLStack()

@property(nonatomic, strong) NSMutableArray *container;

@end

@implementation JLStack

- (id)pop
{
    return [self.container lastObject];
}

- (void)push:(id)object
{
    if (object) {
        [self.container addObject:object];
    }
}

- (BOOL)isEmpty
{
    return self.length == 0;
}

- (NSUInteger)length
{
    return [self.container count];
}

@end
