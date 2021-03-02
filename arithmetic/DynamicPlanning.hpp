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

#endif /* DynamicPlanning_hpp */
