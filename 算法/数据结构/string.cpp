//
//  string.cpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/21.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "string.hpp"
#include <limits.h>

//暴力匹配
int indexSubString(std::string s,std::string t,int pos)
{
    size_t sLength = s.length();
    size_t tLength = t.length();
    //从pos位置开始匹配
    int i = pos;
    int j = 1;
    while (i<=sLength && j<tLength) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {//指针后退重新开始匹配
            //i退回到上次匹配首位的下一位
            i = i-j+2;
            //j退回到子串T的首位
            j = 1;
        }
        
    }
    if (j == tLength) {
        return i - tLength;
    } else {
        return 0;
    }
}
