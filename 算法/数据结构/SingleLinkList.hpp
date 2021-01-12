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
    Node *m_tail;
    int value;
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
};

template <class T>
SingleLinkList<T>::SingleLinkList(){
    m_size = 0;
    m_head = m_tail = NULL;
}

template <class T>
SingleLinkList<T>::~SingleLinkList()
{
    std::cout << "dealloc:" << this->m_size << std::endl;
}

template <class T>
void SingleLinkList<T>::addNodeToHead(T n)
{
    Node *newNode = new Node(n);
    if (m_head == NULL) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->next = m_head;
        m_head = newNode;//插入到表头
    }
    
    m_size++;
}

template <class T>
void SingleLinkList<T>::add(T n)
{
    Node *newNode = new Node(n);
   
    if (m_tail == NULL) {
        m_tail = newNode;
        m_head = newNode;
    } else {
        m_tail->next = newNode;//插入到表尾
        m_tail = newNode;
    }
    m_size++;
}

template <class T>
void SingleLinkList<T>::clear()
{
    Node *head = m_head;
    while (head) {
        Node *tmp = head;
        delete tmp;
        head = head->next;
        m_size--;
    }
    if (m_size == 0) {
        m_head = NULL;
        m_tail = NULL;
    }
}

template <class T>
T SingleLinkList<T>::get(int index)
{
    rangeCheck(index);
    T value = NULL;
    int i = 0;
    Node *head = m_head;
    while (head) {
        i++;
        head = head->next;
        if (i == index) {
            value = head->_value;
            break;
        }
    }
    return value;
}

template <class T>
void SingleLinkList<T>::addAtIndex(int index,T value)
{
    Node *head = m_head;
    int i = 0;
    while (head) {
        if (i == index - 1) {
            Node *node = new Node(value);
            node->next = head->next;
            head->next = node;
            m_size++;
            break;
        }
        head = head->next;
        i++;
    }
}

template <class T>
T SingleLinkList<T>::remove(int index)
{
    Node *targetNode = NULL;
    Node *head = m_head;
    int i = 0;
    while (head) {
        //找到index-1的位置,通过next指针找到目标结点
        if (i == index - 1) {
            targetNode = head->next;
            head->next = head->next->next;
            break;
        }
        head = head->next;
        i++;
    }
    T value = NULL;
    if (targetNode) {
        value = targetNode->_value;
        delete targetNode;
        m_size--;
    }
    return value;
}

template <class T>
std::string SingleLinkList<T>::toString()
{
    Node *head = m_head;
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
