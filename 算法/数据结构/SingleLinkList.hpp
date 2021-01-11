//
//  SingleLinkList.hpp
//  1-1链表
//
//  Created by Wangjianlong on 2019/2/17.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Config.h"

//定义单链表

//第一种写法
//struct Node {
//    int val;
//    struct Node *next;
//};
//typedef struct Node *LinkList;

//第二种写法
typedef struct Node {
    int val;
    struct Node *next;
}Node, *LinkList;

/// 向链表头部插入数据
/// @param p 链表p
/// @param n 数据n
void creatLinkListHead(LinkList *p,int n);

/// 向链表尾部插入数据
/// @param p 链表p
/// @param n 数据n
void creatLinkListTail(LinkList *p,int n);

/// 删除链表
/// @param l 链表l
Status deleteLinkList(LinkList *l);

/// 从链表中i位置处获取元素
/// @param L 链表l
/// @param i 元素i
/// @param value 存储到value中
Status getElement(LinkList *L,int i,int *value);

/// 在链表位置处插入数据
/// @param L 链表
/// @param i index
/// @param value 数据
Status insertList(LinkList *L,int i,int value);

/// 从链表i处删除元素
/// @param L 链表
/// @param i index
/// @param value 数据
Status deletEleList(LinkList *L,int i,int *value);

//template <class T>
//class SingleLinkList {
//
//public:
//    T value;
//    SingleLinkList *next;
//    SingleLinkList(T v);
//    void creatLinkListHead(SingleLinkList *l,T n);
//    void creatLinkListTail(SingleLinkList *l,T n);
//    Status deleteLinkList(SingleLinkList *l);
//    Status getElement(SingleLinkList *l,T i,T *value);
//    Status insertList(SingleLinkList *l,T i,T value);
//    Status deletEleList(SingleLinkList *l,T i,T *value);
//};

//class SingleLinkList {
//
//public:
//    int value;
//    SingleLinkList *next;
//    SingleLinkList(int v);
//    ~SingleLinkList();
//    void addNodeToHead(int n);
//    void addNodeToTail(int n);
//    Status deleteLinkList();
//    Status getElement(int i,int *value);
//    Status insertList(int i,int value);
//    Status deletEleList(int i,int *value);
//    void printFromHeadToTail();
//};
template <class T>
class SingleLinkList {
    
public:
    int value;
    SingleLinkList *next;
    SingleLinkList(T v);
    ~SingleLinkList();
    void addNodeToHead(T n);
    void addNodeToTail(T n);
    Status deleteLinkList();
    Status getElement(int index,T *value);
    Status insertList(int index,T value);
    Status deletEleList(int index,T *value);
    void printFromHeadToTail();
};
