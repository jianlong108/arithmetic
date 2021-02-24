//
//  BindaryTree.hpp
//  算法
//
//  Created by JL on 2021/1/27.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef BindaryTree_hpp
#define BindaryTree_hpp

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
    int m_val;
    TreeNode *m_left;
    TreeNode *m_right;
    
public:
    TreeNode(int v,TreeNode *l, TreeNode *r):m_val(v),m_left(l),m_right(r) {}
    ~TreeNode(){}
    
    //前序遍历
    void preOrderTraverse(TreeNode *root);
    //中序遍历
    void inOrderTraverse(TreeNode *root);
    //后序遍历
    void PostOrderTraverse(TreeNode *root);
};

void TreeNode::preOrderTraverse(TreeNode *root)
{
    if (root == NULL) {
        return ;
    }
    stack<TreeNode *> s;
//    vector<int> res = new vector();
    
    s.push(root);
    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
//        res.push_back(node->m_val);
        cout << node->m_val <<endl;
        if (node->m_right != NULL) {
            s.push(node->m_right);
        }
        if (node->m_left != NULL) {
            s.push(node->m_left);
        }
    }
}

void TreeNode::inOrderTraverse(TreeNode *root)
{
    if (root == NULL) {
        return ;
    }
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur != NULL || !s.empty()) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->m_left;
        }
        cur = s.top();
        cout << cur->m_val << endl;
        cur = cur->m_right;
    }
}

//后序遍历
void TreeNode::PostOrderTraverse(TreeNode *root)
{
    if (root == NULL) {
        return ;
    }
    stack<TreeNode *> s;
    TreeNode *cur = root;
    TreeNode *last = NULL;
    while (cur != NULL || !s.empty()) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->m_left;
        }
        cur = s.top();
        if (cur->m_right == NULL || cur == last) {
            cout << cur->m_val << endl;
            s.pop();
            last = cur;
            cur = NULL;
        } else {
            cur = cur->m_right;
        }
    }
    
}

#endif /* BindaryTree_hpp */
