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
vector<int> twoSum_hash(vector<int>& nums, int target) {
    vector<int> v1;
    map<int,int> tmpMap;
    for (int i = 0; i<nums.size(); i++) {
        tmpMap.insert(map<int, int>::value_type(nums[i],i));
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

#endif /* _______hpp */
