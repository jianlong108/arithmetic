//
//  Tree.cpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/22.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "Tree.hpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void preOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    cout << T->data <<endl;
    
    //先序遍历左子树
    preOrderTraverse(T->lchild);
    //最后先序遍历右子树
    preOrderTraverse(T->rchild);
}

void inOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    inOrderTraverse(T->lchild);
    cout << T->data <<endl;
    inOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL) {
        return;
    }
    inOrderTraverse(T->lchild);
    inOrderTraverse(T->rchild);
    cout << T->data <<endl;
}

void creatBigTree(BiTree *T)
{
    char ch;
    cout << "请输入一个字符" << endl;
    cin >> ch;
    
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T) {
            (*T)->data = ch;
            creatBigTree(&(*T)->lchild);
            creatBigTree(&(*T)->rchild);
        }
    }
}


class solutaion {
    
public:
    
    //前序遍历  根左右
    vector<char > preorderTraversal(BiTree root)
    {
        vector<char>res;
        stack<BiTree >s;
        BiTree p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.push_back(p->data);
                p = p->lchild;
            } else {
                BiTree t = s.top();
                s.pop();
                p = t->rchild;
            }
        }
        
        return res;
    }
    
    //中序遍历  左根右
    vector<char > inorderTraversal(BiTree root)
    {
        vector<char>res;
        stack<BiTree >s;
        BiTree p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->lchild;
            } else {
                BiTree t = s.top();
                s.pop();
                res.push_back(t->data);
                p = p->rchild;
            }
        }
        
        return res;
    }
    
    //后序遍历  左右根
    vector<char > backorderTraversal(BiTree root)
    {
        vector<char>res;
        stack<BiTree >s;
        BiTree p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->lchild;
            } else {
                BiTree t = s.top();
                s.pop();
                res.push_back(t->data);
                p = p->rchild;
                
                s.push(p);
                res.push_back(p->data);
            }
        }
        
        return res;
    }
};
