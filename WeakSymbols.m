//
//  WeakSymbols.m
//  arithmetic
//
//  弱符号默认实现文件
//

#import <Foundation/Foundation.h>

// 提供弱符号的空实现
// 如果有强符号实现，链接器会优先使用强符号
// 如果没有，使用这个空实现，函数指针不会为 NULL
__attribute__((weak))
void weak_func_hookName(int age) {
    // 空实现 - 什么都不做
}
