//
//  螺旋矩阵.hpp
//  算法
//
//  Created by Wangjianlong on 2021/1/23.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef _____hpp
#define _____hpp
/**
 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 输入:
 [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
 ]
 输出: [1,2,3,6,9,8,7,4,5]
 
 输入:
 [
   [1, 2, 3, 4],
   [5, 6, 7, 8],
   [9,10,11,12]
 ]
 输出: [1,2,3,4,8,12,11,10,9,5,6,7]

 */
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) {
                ans.push_back(matrix[u][i]); //向右移动直到最右
            }
            if(++ u > d) {
                break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            }
            for(int i = u; i <= d; ++i) {
                ans.push_back(matrix[i][r]); //向下
            }
            if(-- r < l) {
                break; //重新设定有边界
            }
            for(int i = r; i >= l; --i) {
                ans.push_back(matrix[d][i]); //向左
            }
            if(-- d < u) {
                break; //重新设定下边界
            }
            for(int i = d; i >= u; --i) {
                ans.push_back(matrix[i][l]); //向上
            }
            if(++ l > r) {
                break; //重新设定左边界
            }
        }
        return ans;
    }
};

#endif /* _____hpp */
