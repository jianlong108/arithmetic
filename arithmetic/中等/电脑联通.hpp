//
//  电脑联通.hpp
//  算法
//
//  Created by Wangjianlong on 2021/1/24.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef _____hpp
#define _____hpp

#include <stdio.h>
//https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/solution/wang-luo-lian-jie-bing-cha-ji-by-yexiso-1nd4/
using namespace std;

// 注意：使用该代码，并不能使得所有的元素都直接指向根节点，仍然存在间接的指向
class QuickUnion_s {
private:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    int count;         // 记录连通分量的个数
    int rest;          // 记录多余的连接数
public:
    QuickUnion_s(int n): parent(vector<int>(n)), rank(vector<int>(n)), count(n), rest(0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            // 按秩合并
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            count--;
        } else {
            rest++;
        }
    }
    int getCount() {
        return count;
    }
    int getRest() {
        return rest;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        QuickUnion_s ds(n);
        for (auto& e :connections) {
            ds.merge(e[0], e[1]);
        }
        if (ds.getRest() < ds.getCount() - 1) return -1;
        return ds.getCount() - 1;
    }
};

#endif /* _____hpp */
