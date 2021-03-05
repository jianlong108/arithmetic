//
//  ArrayAndString.hpp
//  arithmetic
//
//  Created by JL on 2021/3/2.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef ArrayAndString_hpp
#define ArrayAndString_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/*
 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 [
   [1,   4,  7, 11, 15],
   [2,   5,  8, 12, 19],
   [3,   6,  9, 16, 22],
   [10, 13, 14, 17, 24],
   [18, 21, 23, 26, 30]
 ]
 链接：https://leetcode-cn.com/leetbook/read/illustrate-lcof/xz2hh7/
 */
bool findNumberIn2DArray(vector<vector<int>> matrix ,int target)
{
    if (matrix.size() == 0) {
        return false;
    }
    int x = 0;
    unsigned long y = matrix.size() - 1;
    while (x < matrix[0].size() && y >= 0) {
        int cur = matrix[x][y];
        if (cur > target) {
            y--;
        } else if (cur < target) {
            x++;
        } else {
            return true;
        }
        
    }
    
    return false;
}
void TestFindNumberIn2DArray()
{
    vector<vector<int>> m = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    cout << findNumberIn2DArray(m,16) << endl;
}
/*
 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
string replaceSpace(string s)
{
    string newStr = string("");
    for (int i = 0; i< s.size(); i++) {
        char c = s.at(i);
        if (c == ' ') {
            newStr.append("%20");
        } else {
            newStr.append((char *)&c);
        }
    }
    return newStr;
}

void TestreplaceSpace()
{
    
    cout << replaceSpace("i love you") << endl;
}

/*
 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
有规律的数组查找 都是使用二分查找
 */
int minArray(vector<int> numbers) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (numbers[mid] < numbers[right]) {
            right = mid;
        } else if (numbers[mid] > numbers[right]) {
            left = mid + 1;
        } else {
            right --;
        }
    }
    return numbers[left];
}

void TestminArray()
{
    vector<int> m = {3,4,7,11,15,1,2};
    cout << minArray(m) << endl;
}

/*
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */
vector<int> exchange(vector<int> nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while(start < end) {
        while(start < end && (nums[start] % 2) == 1) {
            start++;
        }
        while(start < end && (nums[end] % 2) == 0) {
            end--;
        }
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
    }
    return nums;
}

void TestExchange()
{
    vector<int> m = {1,2,3,4,5,6,7};
    vector<int> n = exchange(m);
    for(int j=0;j<n.size();j++)
    {
        cout<<n[j]<<" ";
    }
}

vector<int> spiralOrder(vector<vector<int>> matrix) {
    if(matrix.size() == 0) return vector<int>();
    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1, x = 0;
    vector<int> res;
    while(true) {
        for(int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
            cout << matrix[top][i] << " " ;
        }
        if(++top > bottom) break;
        for(int i = top; i <= bottom; i++) {
//            res[x++] = matrix[i][right];
            res.push_back(matrix[i][right]);
            cout << matrix[i][right] << " " ;
        }
        if(left > --right) break;
        for(int i = right; i >= left; i--) {
//            res[x++] = matrix[bottom][i];
            res.push_back(matrix[bottom][i]);
            cout << matrix[bottom][i] << " " ;
            
        }
        if(top > --bottom) break;
        for(int i = bottom; i >= top; i--) {
//            res[x++] = matrix[i][left];
            res.push_back(matrix[i][left]);
            cout << matrix[i][left] << " " ;
            
        }
        if(++left > right) break;
    }
    
    cout << endl;
    return res;
}

void TestSpiralOrder()
{
    vector<vector<int>> m = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}};
    vector<int> v = spiralOrder(m);
    for(int j=0;j<v.size();j++) {
        cout << v[j] << " ";
    }
    cout << endl;
}

#endif /* ArrayAndString_hpp */
