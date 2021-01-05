//
//  3-无重复字符的最长子串.cpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#include "3-无重复字符的最长子串.hpp"

#include <map>
#include<set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 1;
    }
    //定义了一个string类型的迭代器ite，迭代器就相当于一个指针，一个string类型的迭代器就是一个指向string对象元素的char *指针，本质就是char *指针，用法也跟指针一样
    
    //    string::iterator iter = s.begin();
    int maxLength = 0;
    int tmp = 1;
    for (size_t i = 0; i < s.size(); i++) {
        tmp = 1;
        for (size_t j = i+1; j<=s.size(); j++) {
            string subStr = s.substr(i,tmp);
            maxLength = maxLength < subStr.length() ? subStr.length(): maxLength;
            if (j < s.size()) {
                if (subStr.find(s.at(j),0) != string::npos){
                    
                    break;
                }
            }
            
            tmp ++;
        }
        
    }
    return maxLength;
}

//滑动窗口
//https://www.cnblogs.com/caiyishuai/p/8646345.html
int charSet_lengthOfLongestSubstring(string s) {
    size_t length = s.size();
    set<char>charSet = set<char>();
    int maxlength = 0,i=0,j=0;
    while (i<length && j<length) {
        //没找到char..
        if (charSet.find(s.at(j)) == charSet.end()) {
            charSet.insert(s.at(j));
            j++;
            maxlength = max(maxlength, j-i);
        } else {
            charSet.erase(s.at(i));
            i++;
        }
    }
    return maxlength;
}

//滑动窗口
int charMap_lengthOfLongestSubstring(string s) {
    size_t length = s.size();
    map<char,int> charMap = map<char,int>();
    
    int maxlength = 0;
    for (int i=0,j=0; j<length; j++) {
        map<char,int>::iterator it = charMap.find(s.at(j));
        if (it != charMap.end() ) {
            i = max(i, it->second);
        }
        maxlength = max(maxlength, j-i+1);
        //        charMap.insert(pair<char,int>(s.at(j),j+1));//不会覆盖已有的数据，造成最新数据无法插入
        charMap[s.at(j)] = j+1;
    }
    return maxlength;
}
