//
//  main.mm
//  arithmetic
//
//  Created by wangjianlong on 2019/2/14.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int name = 1;
//int name;

static int age = 2;
double height __attribute__((visibility("hidden"))) = 2.5;

void aab() {
    NSLog(@"aab");
}

static void abb(int a) {
    NSLog(@"abb %d",a);
}



int main(int argc, const char * argv[]) {
    
    NSLog(@"hello, world!");
//    [[Person new] print];
    if (weak_func_hookName) {
        weak_func_hookName(1);
    }
    return 0;
}

