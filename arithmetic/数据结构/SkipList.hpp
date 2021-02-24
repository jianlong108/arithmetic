//
//  SkipList.hpp
//  算法
//
//  Created by JL on 2021/2/22.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef SkipList_hpp
#define SkipList_hpp

#include <stdio.h>
//#include <r>

template <class T>
class SkipNode {
    int key;
    T value;
    SkipNode right,down;
public:
    SkipNode (int key, T value) {
        this->key = key;
        this->value = value;
    }
};

template <class T>
class SkipList {
    SkipNode headNode; //头结点 入口
    int highLevel; //当前跳表索引层数
    int random; //用于投郑硬币
    int MAX_LEVEL = 32; //最大的层
    
public:
    SkipList() {
        this->random = 0;
        
    }
};

#endif /* SkipList_hpp */
