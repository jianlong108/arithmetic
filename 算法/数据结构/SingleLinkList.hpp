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
    int m_size;
    
public:
    int value;
    SingleLinkList *next;
    SingleLinkList(T v);
    ~SingleLinkList();
    void addNodeToHead(T e);
    void add(T e);
    void clear();
    T get(int index);
    void addAtIndex(int index,T value);
    T remove(int index);
    std::string toString();
};

template <class T>
SingleLinkList<T>::SingleLinkList(T v){
    this->value = v;
    this->next = NULL;
    this->m_size = 0;
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
void SingleLinkList<T>::add(T n)
{
    SingleLinkList *tmp = this;
    for (int i=0; i<=n; i++) {
        SingleLinkList *newNode = new SingleLinkList(i);
        tmp->next = newNode;//插入到表尾
        tmp = newNode;
    }
}

template <class T>
void SingleLinkList<T>::clear()
{
    SingleLinkList *head = this;
    SingleLinkList *next = head->next;
    while (next) {
        head = next;
        next = next->next;
        delete head;
    }
}

template <class T>
T SingleLinkList<T>::get(int index)
{
    SingleLinkList *cur = this;
    SingleLinkList *next = cur->next;
    T value = NULL;
    int i = 0;
    while (next) {
        cur = next;
        next = next->next;
        if (i == index) {
            value = cur->value;
            break;
        }
        i++;
    }
    return value;
}

template <class T>
void SingleLinkList<T>::addAtIndex(int index,T value)
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
}

template <class T>
T SingleLinkList<T>::remove(int index)
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
    T value = NULL;
    if (targetNode) {
        value = targetNode->value;
        delete targetNode;
    }
    return value;
}

template <class T>
std::string SingleLinkList<T>::toString()
{
    SingleLinkList *head = this;
    std::string s("单向链表:");
    while (head) {
        std::string s1 = std::to_string(head->value);
        s += s1;
        head = head->next;
        if (head) {
            s+="->";
        }
    }
    return s;
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
