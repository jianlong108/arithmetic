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

/* // 没有使用模板的情况
class SingleLinkList {

public:
    int value;
    SingleLinkList *next;
    SingleLinkList(int v);
    ~SingleLinkList();
    void addNodeToHead(int n);
    void addNodeToTail(int n);
    Status deleteLinkList();
    Status getElement(int i,int *value);
    Status insertList(int i,int value);
    Status deletEleList(int i,int *value);
    void printFromHeadToTail();
};
*/
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

template <class T>
SingleLinkList<T>::SingleLinkList(T v){
    this->value = v;
    this->next = NULL;
    std::cout << "init:" << this->value << std::endl;
}

template <class T>
SingleLinkList<T>::~SingleLinkList()
{
    std::cout << "dealloc:" << this->value << std::endl;
}
template <class T>
void SingleLinkList<T>::addNodeToHead(T n)
{
    SingleLinkList *tmp;
    for (int i=0; i<=n; i++) {
        tmp = new SingleLinkList(i);
        tmp->next = this->next;
        this->next = tmp;//插入到表头
    }
}
template <class T>
void SingleLinkList<T>::addNodeToTail(T n)
{
    SingleLinkList *tmp = this;
    for (int i=0; i<=n; i++) {
        SingleLinkList *newNode = new SingleLinkList(i);
        tmp->next = newNode;//插入到表尾
        tmp = newNode;
    }
}
template <class T>
Status SingleLinkList<T>::deleteLinkList()
{
    SingleLinkList *head = this;
    SingleLinkList *next = head->next;
    while (next) {
        head = next;
        next = next->next;
        delete head;
    }
    return OK;
}
template <class T>
Status SingleLinkList<T>::getElement(int index,T *value)
{
    SingleLinkList *cur = this;
    SingleLinkList *next = cur->next;
    int i = 0;
    while (next) {
        cur = next;
        next = next->next;
        if (i == index) {
            *value = cur->value;
            break;
        }
        i++;
    }
    if (i != index) {
        return Error;
    }
    return OK;
}
template <class T>
Status SingleLinkList<T>::insertList(int index,T value)
{
    SingleLinkList *cur = this;
    SingleLinkList *next = cur->next;
    int i = 0;
    while (next) {
        cur = next;
        next = next->next;
        if (i == index - 1) {
            SingleLinkList *node = new SingleLinkList(value);
            cur->next = node;
            node->next = next;
            break;
        }
        i++;
    }
    if (i != index) {
        return Error;
    }
    return OK;
}
template <class T>
Status SingleLinkList<T>::deletEleList(int index,T *value)
{
    SingleLinkList *cur = this;
    SingleLinkList *next = cur->next;
    int i = 0;
    SingleLinkList *targetNode = NULL;
    while (next) {
        cur = next;
        next = next->next;
        if (i == index - 1) {
            targetNode = cur->next;
            cur->next = cur->next->next;
            break;
        }
        i++;
    }
    if (targetNode) {
        *value = targetNode->value;
        delete targetNode;
    }
    return OK;
}

template <class T>
void SingleLinkList<T>::printFromHeadToTail()
{
    SingleLinkList *head = this;
    while (head) {
        std::cout << "从头到尾遍历:" << head->value << std::endl;
        head = head->next;
    }
}


//第一种写法--------------------------------------------------------
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
