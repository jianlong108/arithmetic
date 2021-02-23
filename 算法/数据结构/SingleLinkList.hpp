//
//  SingleLinkList.hpp
//  算法-单向链表
//
//  Created by Wangjianlong on 2019/2/17.
//  Copyright © 2019 JL.Com. All rights reserved.
//
#pragma once

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
class Node {
public:
    T _value;
    Node *next;
    Node(T value):_value(value){
        next = NULL;
        std::cout << "init:" << _value << std::endl;
    };
    ~Node(){
        std::cout << "dealloc:" << _value << std::endl;
    }
    std::string toString()
    {
        Node<T> *head = this;
        std::string s("元素:");
        while (head) {
            std::string s1 = std::to_string(head->_value);
            s += s1;
            head = head->next;
            if (head) {
                s+="->";
            }
        }
        return s;
    }
};

template <class T>
class SingleLinkList {
    int m_size;
    
public:
    Node<T> *m_head;
    SingleLinkList();
    ~SingleLinkList();
    void addNodeToHead(T e);
    void add(T e);
    void clear();
    T get(int index);
    void addAtIndex(int index,T value);
    T remove(int index);
    std::string toString();
    void rangeCheck(int index) {
        if (index < 0 || index >= m_size) {
            throw "outOfBounds:index:" + std::to_string(index)+" size:" + std::to_string(m_size);
        }
    }
    int size() {
        return m_size;
    }
    bool isEmpty() {
        return m_size == 0;
    }
    Node<T> *nodeAtIndex(int index) {
        rangeCheck(index);
        Node<T> *head = m_head;
        for (int i=0;i<index;i++) {
            head = head->next;
        }
        return head;
    }
};

template <class T>
SingleLinkList<T>::SingleLinkList(){
    m_size = 0;
    m_head = NULL;
}

template <class T>
SingleLinkList<T>::~SingleLinkList()
{
    std::cout << "dealloc:" << this->m_size << std::endl;
}

template <class T>
void SingleLinkList<T>::addNodeToHead(T n)
{
    Node<T> *newNode = new Node<T>(n);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        newNode->next = m_head;
        m_head = newNode;//插入到表头
    }
    
    m_size++;
}

template <class T>
void SingleLinkList<T>::add(T value)
{
    addAtIndex(m_size-1, value);
}

template <class T>
void SingleLinkList<T>::addAtIndex(int index,T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        Node<T> *node = nodeAtIndex(m_size-1);
        node->next = newNode;
    }
    m_size++;
}

template <class T>
void SingleLinkList<T>::clear()
{
    Node<T> *head = m_head;
    while (head) {
        Node<T> *tmp = head;
        delete tmp;
        head = head->next;
        m_size--;
    }
    if (m_size == 0) {
        m_head = NULL;
    }
}

template <class T>
T SingleLinkList<T>::get(int index)
{
    rangeCheck(index);
    Node<T> *head = nodeAtIndex(index);
    return head->_value;
}



template <class T>
T SingleLinkList<T>::remove(int index)
{
    rangeCheck(index);
    Node<T> *indexNode = NULL;
    if (index == 0) {
        indexNode = m_head;
        m_head = m_head->next;
    } else {
        Node<T> *preNode = nodeAtIndex(index - 1);
        indexNode = preNode->next;
        preNode->next = indexNode->next;
    }
    T v = indexNode->_value;
    delete indexNode;
    m_size--;
    return v;
}

template <class T>
std::string SingleLinkList<T>::toString()
{
    Node<T> *head = m_head;
    std::string s("单向链表长度:");
    s += std::to_string(m_size);
    s += " 元素为:";
    while (head) {
        std::string s1 = std::to_string(head->_value);
        s += s1;
        head = head->next;
        if (head) {
            s+="->";
        }
    }
    return s;
}

/*
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
*/
