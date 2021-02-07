//
//  QuickUnion.hpp
//  算法
//
//  Created by Wangjianlong on 2021/1/24.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef QuickUnion_hpp
#define QuickUnion_hpp

#include <stdio.h>

using namespace std;

class QuickUnion {
    vector<int> parents;
    
public:
    QuickUnion(int capacity) {
        parents = vector<int> (capacity);
        for (int i = 0; i < capacity; i++) {
            parents[i] = i;
        }
    }
    ~QuickUnion(){
        
    }
    int find(int v) {
        rangCheck(v);
        while (v != parents[v]) {
            v = parents[v];
        }
        return v;
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
        parents[p1] = p2;
        return true;
    }
};

#endif /* QuickUnion_hpp */
