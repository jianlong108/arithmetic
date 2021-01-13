//
//  CircleLinkList.hpp
//  算法-双向循环链表
//
//  Created by Wangjianlong on 2021/1/12.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Config.h"

using namespace std;

template <class T>
class CircleLinkList {
    int m_size;
    
public:
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
    Node *m_head;
    int value;
    CircleLinkList();
    ~CircleLinkList();
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
CircleLinkList<T>::CircleLinkList(){
    m_size = 0;
    m_head = NULL;
    cout << "CircleLinkList():" << m_size << endl;
}

template <class T>
CircleLinkList<T>::~CircleLinkList()
{
    cout << "~CircleLinkList():" << m_size << endl;
}

template <class T>
void CircleLinkList<T>::addNodeToHead(T value)
{
    Node *newNode = NULL;
    if (m_head == NULL) {
        newNode = new Node(value,NULL,NULL);
        m_head = newNode;
    } else {
        newNode = new Node(value,m_head,m_head->m_pre);
        m_head->m_next->m_pre = newNode;
        m_head->m_pre = newNode;
        m_head = newNode;//插入到表头
    }
    m_size++;
    Node *lastNode = nodeAtIndex(m_size - 1);
    lastNode->m_next = newNode;
}

template <class T>
void CircleLinkList<T>::add(T value)
{
    addAtIndex(m_size-1, value);
}

template <class T>
void CircleLinkList<T>::addAtIndex(int index,T value)
{
    Node *newNode = NULL;
    if (m_head == NULL) {
        newNode = new Node(value,NULL,NULL);
        m_head = newNode;
    } else {
        Node *node = nodeAtIndex(m_size-1);
        newNode = new Node(value,node->m_next,node);
        node->m_next = newNode;
        newNode->m_next = m_head;
        m_head->m_pre = newNode;
    }
    m_size++;
}

template <class T>
void CircleLinkList<T>::clear()
{
    for (int i = 0; i<m_size; i++) {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
    m_size = 0;
    m_head = NULL;
}

template <class T>
T CircleLinkList<T>::get(int index)
{
    rangeCheck(index);
    Node *head = nodeAtIndex(index);
    return head->m_value;
}



template <class T>
T CircleLinkList<T>::remove(int index)
{
    rangeCheck(index);
    Node *indexNode = NULL;
    if (index == 0) {
        indexNode = m_head;
        m_head->m_next->m_pre = m_head->m_pre;
        m_head->m_pre->m_next = m_head->m_next;
        m_head = m_head->m_next;
        
    } else {
        Node *preNode = nodeAtIndex(index - 1);
        indexNode = preNode->m_next;
        preNode->m_next = indexNode->m_next;
        preNode->m_next->m_pre = preNode;
    }
    T v = indexNode->m_value;
    delete indexNode;
    m_size--;
    return v;
}

template <class T>
std::string CircleLinkList<T>::toString()
{
    Node *head = m_head;
    std::string s("双向循环链表长度:");
    s += std::to_string(m_size);
    s += " 元素为:";
    for (int i = 0; i<m_size; i++) {
        s += "[";
        s += "前驱:";
        s += to_string(head->m_pre->m_value);
        s += " (";
        s += to_string(head->m_value);
        s += ") 后继:";
        head = head->m_next;
        s += to_string(head->m_value);;
        s += "]";
        if (i!=m_size-1) {
            s+="==>";
        }
    }
    return s;
}
