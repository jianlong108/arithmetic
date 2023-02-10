//
//  5-stringFlip.hpp
//  arithmetic
//
//  Created by JL on 2023/2/9.
//  Copyright © 2023 wangjianlong. All rights reserved.
//

#ifndef __stringFlip_h
#define __stringFlip_h
/*
 给你一个包含若干单词和空格的字符串 s，请你写一个算法，原地反转所有单词的顺序。

 比如说，给你输入这样一个字符串：
 hello world
 
 world hello
 */

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//class solution {

string flipString(string s) {
    if (s.size() < 1) {
        return s;
    }
    unsigned long left = 0;
    unsigned long right = s.size() - 1;
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}

string flipWord(string word) {
    
    cout << "原始字符串:" << word << endl;
    if (word.size() < 1) {
        return word;
    }
    
    string flipStr = flipString(word);
    
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = flipStr.find(space_delimiter)) != string::npos) {
        string substr = flipStr.substr(0, pos);
        if (substr.size() > 0) {
            words.push_back(substr);
        }
        
        flipStr.erase(0, pos + space_delimiter.length());
    }
    if (flipStr.size() > 0) {
        words.push_back(flipStr);
    }
    
    
    string newStr = "";
    for (const auto &str : words) {
        newStr += flipString(str);
        newStr += " ";
    }
    newStr.erase(newStr.size() - 1);
    
    cout << "翻转后的:" << newStr << endl;
    return newStr;
}

string reverseWords(string s) {
    // 反转整个字符串
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
        if (s[start] != ' ') {
            // 填一个空白字符然后将idx移动到下一个单词的开头位置
            if (idx != 0) s[idx++] = ' ';

            // 循环遍历至单词的末尾
            int end = start;
            while (end < n && s[end] != ' ') {
                s[idx++] = s[end++];
            }

            // 反转整个单词
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // 更新start，去找下一个单词
            start = end;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}
//}

#endif /* __stringFlip_h */
