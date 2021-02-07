//
//  3-无重复字符的最长子串.hpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#ifndef _____________hpp
#define _____________hpp

#include <stdio.h>

#include <iostream>

//#include <map>
#include<set>
using namespace std;

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 
 示例 1:
 
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:
 
 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 示例 3:
 
 输入: "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */


//2.滑动窗口 set
//https://www.cnblogs.com/caiyishuai/p/8646345.html
int charSet_lengthOfLongestSubstring(string s) {
    size_t length = s.size();
    set<char>charSet = set<char>();
    int maxlength = 0,left=0,right=0;
    while (left<length && right<length) {
        if (charSet.find(s.at(right)) == charSet.end()) {//没找到char..
            charSet.insert(s.at(right));
            right++;
            maxlength = max(maxlength, right-left);
        } else {
            charSet.erase(s.at(left));
            left++;
        }
    }
    return maxlength;
}

//3.滑动窗口 map
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

//1.暴力解法
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

/*
 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

 返回仅包含 1 的最长（连续）子数组的长度。
 */

int longestOnes(vector<int>& A, int K) {
    int left = 0, right = 0;
    int max = 0;
    while (left <= right && right < A.size()) {
        while (right < A.size() && (A[right] || K != 0)) {
            if (A[right] == 0) K--;
            right++;
        }
        max = std::max(right - left, max);
        if (A[left]){
            left++;
        } else {
            left++;
            right++;
        }
    }
    return max;
}

#endif /* _____________hpp */
