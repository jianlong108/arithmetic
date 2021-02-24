//
//  JLStack.h
//  算法
//
//  Created by Wangjianlong on 2020/12/26.
//  Copyright © 2020 wangjianlong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLStack : NSObject

- (id)pop;
- (void)push:(id)object;
- (BOOL)isEmpty;
- (NSUInteger)length;

@end

NS_ASSUME_NONNULL_END
