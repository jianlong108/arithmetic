//
//  1-两数之和.cpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#include "1-两数之和.hpp"

#include <map>
using namespace std;

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
};

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
