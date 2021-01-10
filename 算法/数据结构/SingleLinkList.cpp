//
//  SingleLinkList.cpp
//  1-1链表
//
//  Created by Wangjianlong on 2019/2/17.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "SingleLinkList.hpp"

/**
 头插法
始终让新结点在第一的位置
 @param p 链表的头指针
 @param n 元素个数
 */
void creatLinkListHead(LinkList *p,int n)
{
    LinkList tmp;
    srand(time(0));
    *p = (LinkList)malloc(sizeof(Node));
    (*p)->next = NULL;
    (*p)->val = n;
    for (int i=0; i<n; i++) {
        tmp = (LinkList)malloc(sizeof(Node));
        tmp->val = rand()%100 + 1;
        tmp->next = (*p)->next;
        (*p)->next = tmp;//插入到表头
        std::cout << "赋值" << tmp->val << std::endl;
    }
}

/**
 尾插法
 
 @param p 链表的头指针
 @param n 元素个数
 */
//void creatLinkListTail(LinkList *p,int n)
//{
//    LinkList tmp;
//    srand(time(0));
//    //游标
//    *p = (LinkList)malloc(sizeof(Node));
//    LinkList head = *p;
//    (*p)->next = NULL;
//    (*p)->val = n;
//    for (int i=0; i<n; i++) {
//        tmp = (LinkList)malloc(sizeof(Node));
//        tmp->val = rand()%100 + 1;
//        
//        (*p)->next = tmp;
//        *p = tmp;
//        std::cout << "赋值" << tmp->val << std::endl;
//    }
//    //结束链表。让其next为NULL
//    (*p)->next = NULL;
//    *p = head;
//}
void creatLinkListTail(LinkList *p,int n)
{
    LinkList tmp;
    srand(time(0));
    *p = (LinkList)malloc(sizeof(Node));
    //指向尾部的结点
    LinkList tail = *p;
    tail->next = NULL;
    tail->val = n;
    for (int i=0; i<n; i++) {
        tmp = (LinkList)malloc(sizeof(Node));
        tmp->val = rand()%100 + 1;
        
        tail->next = tmp;
        tail = tmp;
        std::cout << "赋值" << tmp->val << std::endl;
    }
    //结束链表。让其next为NULL
    tail->next = NULL;
}

Status deleteLinkList(LinkList *l)
{
    //不对
//    LinkList p = *l;
//    LinkList q;
//    while (p->next) {
//        q = p;
//        p = p->next;
//    std::cout << "删除" << q->val << std::endl;
//        free(q);
//    }
    LinkList p,q;
    p = (*l)->next;
    while (p) {
        q = p->next;
        std::cout << "删除" << p->val << std::endl;
        free(p);
        p = q;
    }
    //头结点指针域为空
    (*l)->next = NULL;
    return OK;
}


/**
 获得i位置处的值

 @param L 链表
 @param i 位置 从1开始
 @param value 赋值给value
 @return 状态值
 */
Status getElement(LinkList *L,int i,int *value)
{
    LinkList tmp = *L;
    int j = 1;
    while (tmp && j < i) {
        tmp = tmp ->next;
        j++;
    }
    if (!tmp || j>i) {
        return Error;
    }
    *value = tmp ->val;
    
    return OK;
}


/**
 在L中第i个结点位置之前插入新的数据元素value
 */
Status insertList(LinkList *L,int i,int value)
{
    LinkList tmp = *L;
    int j = 1;
    //找到第i-1个结点
    while (tmp && j<i) {
        tmp = tmp ->next;
        j++;
    }
    if (!tmp ||j>i ) {
        return Error;
    }
    LinkList newNode = (LinkList)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = tmp->next;
    tmp->next = newNode;
    
    return OK;
}

/**
 删除L中的第i个结点，并用value返回其值
 */
Status deletEleList(LinkList *L,int i,int *value)
{
    LinkList tmp = *L;
    int j = 1;
    //找到第i-1个结点
    while (tmp && j<i) {
        tmp = tmp ->next;
        j++;
    }
    if (!(tmp->next) ||j>i ) {
        return Error;
    }
    LinkList deletNode = tmp->next;
    
    tmp->next = deletNode->next ;
    *value = deletNode->val;
    free(deletNode);
    
    
    return OK;
}

//template <class T>
//SingleLinkList<T>::SingleLinkList(T v)
//{
//    value = v;
//    next = NULL;
//}
//
//template <class T>
//void SingleLinkList<T>::creatLinkListHead(SingleLinkList *l,T n)
//{
//    SingleLinkList *tmp;
//    srand(time(0));
//    l = (SingleLinkList *)malloc(sizeof(SingleLinkList));
//    l->next = NULL;
//    l->val = n;
//    for (int i=0; i<n; i++) {
//        tmp = (SingleLinkList *)malloc(sizeof(SingleLinkList));
//        tmp->value = rand()%100 + 1;
//        tmp->next = (*l)->next;
//        l->next = tmp;//插入到表头
//        std::cout << "赋值" << tmp->val << std::endl;
//    }
//}
//
//template <class T>
//void SingleLinkList<T>::creatLinkListTail(SingleLinkList *l,T n)
//{
//    SingleLinkList *tmp;
//    srand(time(0));
//    l = (SingleLinkList *)malloc(sizeof(SingleLinkList));
//    //指向尾部的结点
//    SingleLinkList *tail = l;
//    tail->next = NULL;
//    tail->val = n;
//    for (int i=0; i<n; i++) {
//        tmp = (SingleLinkList *)malloc(sizeof(SingleLinkList));
//        tmp->val = rand()%100 + 1;
//
//        tail->next = tmp;
//        tail = tmp;
//        std::cout << "赋值" << tmp->val << std::endl;
//    }
//    //结束链表。让其next为NULL
//    tail->next = NULL;
//}
//
//template <class T>
//Status SingleLinkList<T>::deleteLinkList(SingleLinkList *l)
//{
//    SingleLinkList *p,*q;
//    p = l->next;
//    while (p) {
//        q = p->next;
//        std::cout << "删除" << p->val << std::endl;
//        free(p);
//        p = q;
//    }
//    //头结点指针域为空
//    l->next = NULL;
//    return OK;
//}
//
//template <class T>
//Status SingleLinkList<T>::getElement(SingleLinkList *l,T i,T *value)
//{
//    SingleLinkList *tmp = l;
//    int j = 1;
//    while (tmp && j < i) {
//        tmp = tmp ->next;
//        j++;
//    }
//    if (!tmp || j>i) {
//        return Error;
//    }
//    *value = tmp ->val;
//
//    return OK;
//}
//
//template <class T>
//Status SingleLinkList<T>::insertList(SingleLinkList *l,T i,T value)
//{
//    SingleLinkList *tmp = l;
//    int j = 1;
//    //找到第i-1个结点
//    while (tmp && j<i) {
//        tmp = tmp ->next;
//        j++;
//    }
//    if (!tmp ||j>i ) {
//        return Error;
//    }
//    SingleLinkList *newNode = (SingleLinkList *)malloc(sizeof(SingleLinkList));
//    newNode->val = value;
//    newNode->next = tmp->next;
//    tmp->next = newNode;
//
//    return OK;
//}
//
//template <class T>
//Status SingleLinkList<T>::deletEleList(SingleLinkList *l,T i,T *value)
//{
//    SingleLinkList *tmp = l;
//    int j = 1;
//    //找到第i-1个结点
//    while (tmp && j<i) {
//        tmp = tmp ->next;
//        j++;
//    }
//    if (!(tmp->next) ||j>i ) {
//        return Error;
//    }
//    SingleLinkList *deletNode = tmp->next;
//
//    tmp->next = deletNode->next ;
//    *value = deletNode->value;
//    free(deletNode);
//
//
//    return OK;
//}

SingleLinkList::SingleLinkList(int v){
    value = v;
    next = NULL;
    std::cout << "init:" << this->value << std::endl;
}

void SingleLinkList::creatLinkListHead(int n)
{
    SingleLinkList *tmp;
    for (int i=n; i>0; i--) {
        tmp = new SingleLinkList(i);
        tmp->next = this->next;
        this->next = tmp;//插入到表头
    }
}

SingleLinkList::~SingleLinkList()
{
    std::cout << "dealloc:" << this->value << std::endl;
}
    
