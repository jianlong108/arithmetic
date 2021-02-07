//
//  1-两数之和.hpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#ifndef _______hpp
#define _______hpp

#include <stdio.h>

#include <vector>
#include <map>
using namespace std;
/*
 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 
 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 
 示例:
 
 给定 nums = [2, 7, 11, 15], target = 9
 
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                v1.push_back(i);
                v1.push_back(j);
                break;
            }
        }
    }
    return v1;
}

/*
 std::map<X, Y>实际储存了一串std::pair<const X, Y>

 std::map<std::string, int> m =
 auto it = m.begin();
 这里，如果你用*it，那么你将得到map第一个元素的std::pair：

 现在你可以接收std::pair的两个元素：

 (*it).first会得到key，

 (*it).second会得到value。

 这等同于it->first和it->second
 */
vector<int> twoSum_hash(vector<int>& nums, int target) {
    vector<int> v1;
    map<int,int> tmpMap;
    for (int i = 0; i<nums.size(); i++) {
//        tmpMap.insert(map<int, int>::value_type(nums[i],i));
        tmpMap.insert(nums[i],i);
    }
    
    for (int i = 0; i < nums.size(); i++) {
        int tmp = target - nums[i];
        map<int,int>::iterator iter = tmpMap.find(tmp);
        if (iter != tmpMap.end() && iter->second != i) {
            v1.push_back(i);
            v1.push_back(iter->second);
            break;
        }
    }
    return v1;
};

/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

 注意：答案中不可以包含重复的三元组。
 输入：nums = [-1,0,1,2,-1,-4]
 输出：[[-1,-1,2],[-1,0,1]]
 
 输入：nums = []
 输出：[]
 
 输入：nums = [0]
 输出：[]
 */

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}
#endif /* _______hpp */
