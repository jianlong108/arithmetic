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

//最长回文子串
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

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 注意：给定 n 是一个正整数。
 */
int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
void TestClimbStairs()
{
    cout << climbStairs(3) << endl;
    cout << climbStairs(5) << endl;
}
/*
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */

int maxSubArray(vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto &x: nums) {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}
void TestmaxSubArray()
{
    vector<int> v({-2,1,-3,4,-1,2,1,-5,4});
    cout << maxSubArray(v) << endl;
}

/*
 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 
 
 如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k~(k>2)k (k>2) 间房屋，有两个选项：

 偷窃第 kk 间房屋，那么就不能偷窃第 k-1k−1 间房屋，偷窃总金额为前 k-2k−2 间房屋的最高总金额与第 kk 间房屋的金额之和。

 不偷窃第 kk 间房屋，偷窃总金额为前 k-1k−1 间房屋的最高总金额。

 在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前 kk 间房屋能偷窃到的最高总金额。

 用 dp[i]dp[i] 表示前 ii 间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：

 \textit{dp}[i] = \max(\textit{dp}[i-2]+\textit{nums}[i], \textit{dp}[i-1])
 dp[i]=max(dp[i−2]+nums[i],dp[i−1])

 边界条件为：

 \begin{cases} \textit{dp}[0] = \textit{nums}[0] & 只有一间房屋，则偷窃该房屋 \\ \textit{dp}[1] = \max(\textit{nums}[0], \textit{nums}[1]) & 只有两间房屋，选择其中金额较高的房屋进行偷窃 \end{cases}
 {
 dp[0]=nums[0]
 dp[1]=max(nums[0],nums[1])
 ​    
   
 只有一间房屋，则偷窃该房屋
 只有两间房屋，选择其中金额较高的房屋进行偷窃
 ​    
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};


void TestDynamicPlanning()
{
    TestUniquePaths();
    TestLongestPalindrome();
    TestClimbStairs();
    TestmaxSubArray();
}
#endif /* DynamicPlanning_hpp */
