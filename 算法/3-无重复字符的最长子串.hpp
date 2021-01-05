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


//1.暴力解法
int lengthOfLongestSubstring(std::string s);
//2.滑动窗口 set
int charSet_lengthOfLongestSubstring(std::string s);

//3.滑动窗口 map
int charMap_lengthOfLongestSubstring(std::string s);

#endif /* _____________hpp */
