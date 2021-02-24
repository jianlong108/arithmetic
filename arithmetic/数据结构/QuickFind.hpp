//
//  QuickFind.hpp
//  算法
//
//  Created by Wangjianlong on 2021/1/24.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef QuickFind_hpp
#define QuickFind_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class QuickFind {
    vector<int> parents;
    
public:
    QuickFind(int capacity) {
        parents = vector<int>(capacity);
        for (int i = 0; i < capacity; i++) {
            parents[i] = i;
        }
    }
    
    ~QuickFind() {
    }
    
    int find(int v) {
        return parents[v];
    }
    bool rangCheck(int v) {
        if (v < 0 || v > parents.size()) {
            throw "v out of range of";
        }
        return true;
    }
    
    bool isSame(int v1, int v2) {
        return find(v1) == find(v2);
    }
    
    bool unionEle(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) {
            return false;
        }
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == p1) {
                parents[i] = p2;
            }
        }
        return 0;
    }
    
};

#endif /* QuickFind_hpp */
