//
//  SingleLinkList.hpp
//  算法
//
//  Created by Wangjianlong on 2021/1/11.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Config.h"


template <class T>
class SingleCircleLinkList {
    int m_size;
    
public:
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
    };
    Node *m_head;
    int value;
    SingleCircleLinkList();
    ~SingleCircleLinkList();
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
    Node *nodeAtIndex(int index) {
        rangeCheck(index);
        Node *head = m_head;
        for (int i=0;i<index;i++) {
            head = head->next;
        }
        return head;
    }
};

template <class T>
SingleCircleLinkList<T>::SingleCircleLinkList(){
    m_size = 0;
    m_head = NULL;
}

template <class T>
SingleCircleLinkList<T>::~SingleCircleLinkList()
{
    std::cout << "dealloc:" << this->m_size << std::endl;
}

template <class T>
void SingleCircleLinkList<T>::addNodeToHead(T n)
{
    Node *newNode = new Node(n);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        newNode->next = m_head;
        m_head = newNode;//插入到表头
    }
    m_size++;
    Node *lastNode = nodeAtIndex(m_size - 1);
    lastNode->next = newNode;
}

template <class T>
void SingleCircleLinkList<T>::add(T value)
{
    addAtIndex(m_size-1, value);
}

template <class T>
void SingleCircleLinkList<T>::addAtIndex(int index,T value)
{
    Node *newNode = new Node(value);
    if (m_head == NULL) {
        m_head = newNode;
    } else {
        Node *node = nodeAtIndex(m_size-1);
        node->next = newNode;
        newNode->next = m_head;
    }
    m_size++;
}

template <class T>
void SingleCircleLinkList<T>::clear()
{
    Node *head = m_head;
    for (int i = 0; i<m_size; i++) {
        Node *tmp = head;
        delete tmp;
        head = head->next;
    }
    m_size = 0;
    m_head = NULL;
}

template <class T>
T SingleCircleLinkList<T>::get(int index)
{
    rangeCheck(index);
    Node *head = nodeAtIndex(index);
    return head->_value;
}



template <class T>
T SingleCircleLinkList<T>::remove(int index)
{
    rangeCheck(index);
    Node *indexNode = NULL;
    if (index == 0) {
        indexNode = m_head;
        m_head = m_head->next;
    } else {
        Node *preNode = nodeAtIndex(index - 1);
        indexNode = preNode->next;
        preNode->next = indexNode->next;
    }
    T v = indexNode->_value;
    delete indexNode;
    m_size--;
    Node *lastNode = nodeAtIndex(m_size - 1);
    if (lastNode) {
        lastNode->next = m_head;
    }
    return v;
}

template <class T>
std::string SingleCircleLinkList<T>::toString()
{
    Node *head = m_head;
    std::string s("单向链表长度:");
    s += std::to_string(m_size);
    s += " 元素为:";
    for (int i = 0; i<m_size; i++) {
        s += "[";
        std::string s1 = std::to_string(head->_value);
        s += s1;
        s += "后继:";
        head = head->next;
        std::string nextStr = std::to_string(head->_value);
        s += nextStr;
        s += "]";
        if (i!=m_size-1) {
            s+="==>";
        }
    }
    return s;
}
