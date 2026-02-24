//
//  Person.h
//  arithmetic
//
//  Created by JL on 2026/2/6.
//  Copyright © 2026 wangjianlong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

// 弱符号声明：结合 weak_import 和 weak
// weak_import: 告诉链接器该符号可以不存在（链接时弱引用）
// weak: 允许提供弱实现
//void weak_func_hookName(int age) __attribute__((weak_import, weak));
void weak_func_hookName(int age) __attribute__((weak));

#ifdef __cplusplus
}
#endif

@interface Person : NSObject

@end

NS_ASSUME_NONNULL_END
