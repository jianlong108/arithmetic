//
//  Person.m
//  arithmetic
//
//  Created by JL on 2026/2/6.
//  Copyright © 2026 wangjianlong. All rights reserved.
//

#import "Person.h"

// 弱符号的默认实现
// 此实现可以被任何提供了相同函数的强符号覆盖
//
// 使用方式：
// 1. 默认情况：使用此空实现，编译通过，运行时 if 检查会通过但函数什么都不做
// 2. 如果需要真正的实现：在其他 .m 文件中提供相同函数（不带 weak 属性）
//    链接器会自动使用强符号，覆盖此弱实现
//
// 注意：在 macOS/iOS 上，无法让弱符号真正为 NULL
// 因为 Apple 链接器不支持 -U 或类似选项可靠地允许未定义符号
// 因此必须提供一个实现（即使是空的）
//__attribute__((weak))
//void weak_func_hookName(int age) {
////     默认空实现
////     如果被调用，说明没有提供强符号实现
////     可以在这里添加日志来调试：
//     NSLog(@"[Weak Symbol] weak_func_hookName called with age=%d (using weak implementation)", age);
//}

@implementation Person

@end
