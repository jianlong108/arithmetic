//
//  LinkList.hpp
//  算法-双向循环链表:增加了尾部结点
//
//  Created by Wangjianlong on 2021/1/12.
//  Copyright © 2019 JL.Com. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <iostream>
#include "Config.h"

using namespace std;

template <class T>
class LinkList
{
    class Node {
    public:
        T m_value;
        Node *m_next;
        Node *m_pre;
        Node(T value,Node *next,Node *pre):m_value(value),m_next(next),m_pre(pre){
            cout << "init:" << m_value << endl;
        };
        ~Node(){
            m_next = NULL;
            m_pre = NULL;
            cout << "dealloc:" << m_value << endl;
        }
    };
    int m_size;
    Node *m_head;
    Node *m_tail;
    
public:
    
    LinkList();
    ~LinkList();
    void addNodeToHead(T e);
    void add(T e);
    void clear();
    T get(int index);
    void addAtIndex(int index,T value);
    T remove(int index);
    string toString();
    void rangeCheck(int index) {
        if (index < 0 || index >= m_size) {
            throw "outOfBounds:index:" + to_string(index)+" size:" + to_string(m_size);
        }
    }
    void rangeCheckForAdd(int index) {
        if (index < 0 || index > m_size) {
            throw "outOfBounds:index:" + to_string(index)+" size:" + to_string(m_size);
        }
    }
    int size() {
        return m_size;
    }
    bool isEmpty() {
        return m_size == 0;
    }
    Node *nodeAtIndex(int index) {
        rangeCheck(index);
        Node *head = m_head;
        for (int i=0;i<index;i++) {
            head = head->m_next;
        }
        return head;
    }
};

template <class T>
LinkList<T>::LinkList(){
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;
    cout << "CircleLinkList():" << m_size << endl;
}

template <class T>
LinkList<T>::~LinkList()
{
    cout << "~CircleLinkList():" << m_size << endl;
}

template <class T>
void LinkList<T>::addNodeToHead(T value)
{
    Node *newNode = NULL;
    if (m_head == NULL) {
        newNode = new Node(value,NULL,NULL);
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode = new Node(value,m_head,m_tail);
        m_head->m_pre = newNode;
        m_head = newNode;//插入到表头
        m_tail->m_next = newNode;
    }
    m_size++;
}

template <class T>
void LinkList<T>::add(T value)
{
    addAtIndex(m_size, value);
}

template <class T>
void LinkList<T>::addAtIndex(int index,T value)
{
    rangeCheckForAdd(index);
    Node *newNode = NULL;
    if (index == m_size) {//往最后插入数据
        Node *preNode = m_tail;
        newNode = new Node(value,m_head,preNode);
        if (preNode) {
            preNode->m_next = newNode;
        }
        if (m_head) {
            m_head->m_pre = newNode;
        } else {
            m_head = newNode;
        }
        m_tail = newNode;
    } else {
        Node *node = nodeAtIndex(index-1);
        newNode = new Node(value,node->m_next,node);
        node->m_next->m_pre = newNode;
        node->m_next = newNode;
    }
    m_size++;
}

template <class T>
void LinkList<T>::clear()
{
    for (int i = 0; i<m_size; i++) {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;
}

template <class T>
T LinkList<T>::get(int index)
{
    rangeCheck(index);
    Node *head = nodeAtIndex(index);
    return head->m_value;
}



template <class T>
T LinkList<T>::remove(int index)
{
    rangeCheck(index);
    Node *indexNode = NULL;
    Node *preNode = NULL;
    if (index == 0) {
        indexNode = m_head;
        preNode = m_head->m_pre;
        m_head = m_head->m_next;
    } else if (index == m_size - 1){
        preNode = m_tail->m_pre;
        indexNode = m_tail;
    } else {
        preNode = nodeAtIndex(index - 1);
        indexNode = preNode->m_next;
    }
    if (preNode) {
        preNode->m_next = indexNode->m_next;
        preNode->m_next->m_pre = preNode;
    }
    
    T v = indexNode->m_value;
    delete indexNode;
    m_size--;
    return v;
}

template <class T>
string LinkList<T>::toString()
{
    Node *head = m_head;
    std::string s("双向循环链表长度:");
    s += std::to_string(m_size);
    s += " 头结点为:[" + to_string(m_head->m_pre->m_value) + "-("+to_string(m_head->m_value)+")-"+to_string(m_head->m_next->m_value) += "]元素为:\n";
    for (int i = 0; i<m_size; i++) {
        s += "["+ to_string(head->m_pre->m_value)+ "-("+ to_string(head->m_value) + ")-" + to_string(head->m_next->m_value)+ "]";
        head = head->m_next;
    
        if (i!=m_size-1) {
            s+="==>";
        }
    }
    return s;
}
