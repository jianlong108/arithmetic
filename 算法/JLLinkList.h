//
//  JLLinkList.h
//  算法
//
//  Created by Wangjianlong on 2020/12/27.
//  Copyright © 2020 wangjianlong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLLinkNode : NSObject

@property(nonatomic, strong) id value;
@property(nonatomic, strong) JLLinkNode *next;
@property(nonatomic, strong) JLLinkNode *prev;

@end

@interface JLLinkList : NSObject

@property(nonatomic, strong) JLLinkNode *head;

- (NSUInteger)length;
- (void)addNode:(JLLinkNode *)node;
- (void)removeNode:(JLLinkNode *)node;
- (void)insertNode:(JLLinkNode *)node at:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
