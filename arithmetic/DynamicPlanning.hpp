//
//  DynamicPlanning.hpp
//  arithmetic
//
//  Created by JL on 2021/3/2.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef DynamicPlanning_hpp
#define DynamicPlanning_hpp

#include <stdio.h>
#include <string.h>

using namespace std;

/*
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

 问总共有多少条不同的路径？
 链接：https://leetcode-cn.com/problems/unique-paths
*/

int uniquePaths(int m, int n) {
    vector<vector<int>> f(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}

void TestUniquePaths()
{
    cout << uniquePaths(2,2) << endl;
    cout << uniquePaths(3,3) << endl;
    cout << uniquePaths(3,7) << endl;
}

string longestPalindrome(string s)
{
    int len = s.size();
    if (len < 2) {
        return s;
    }
    int maxLen = 1;
    int begin = 0;

    // dp[i][j] 表示 s[i, j] 是否是回文串
    vector<vector<int>> dp(len, vector<int>(len));

    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                if (j-i < 3) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            // 只要 dp[i][j] == true 成立，就表示子串 s[i..j] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    
    return s.substr(begin, begin + maxLen);
}

void TestLongestPalindrome()
{
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("babadab") << endl;
}

#endif /* DynamicPlanning_hpp */
