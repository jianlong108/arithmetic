//
//  链表相关.cpp
//  算法
//
//  Created by JL on 2021/2/23.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkList.hpp"
#include <stdlib.h>
#include <time.h>

//反转链表
// 1-2-3-null  ===>  3-2-1-null

Node<int>* reverseList(Node<int>* list) {
    Node<int> *prev = NULL;
    Node<int> *curr = list;
    while (curr) {
        Node<int> *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

void TestReverseList(){
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 1; i<4; i++) {
        Node<int> *newNode = new Node<int>(i);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    cout << head->toString() << endl;
    Node<int> *newList = reverseList(head);
    cout << newList->toString() << endl;
    
}

/*
 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 你应当 保留 两个分区中每个节点的初始相对位置。
1-4-3-2-5-2 x=3 ==> 1-2-2-4-3-5
 */
Node<int>* partition(Node<int>* head, int x) {
    //小链表的头
    Node<int> *smallHead = new Node<int>(0);
    //大链表的头
    Node<int> *bigHead = new Node<int>(0);
    //小链表的尾
    Node<int> *smallTail = smallHead;
    //大链表的尾
    Node<int> *bigTail = bigHead;
    //遍历head链表
    while (head != NULL) {
        if (head->_value < x) {
            //如果当前节点的值小于x，则把当前节点挂到小链表的后面
            smallTail = smallTail->next = head;
        } else {//否则挂到大链表的后面
            bigTail = bigTail->next = head;
        }

        //继续循环下一个结点
        head = head->next;
    }
    //最后再把大小链表拼接在一块即可。
    smallTail->next = bigHead->next;
    bigTail->next = NULL;
    return smallHead->next;
}

void TestPartitionList(){
    srand((unsigned)time(NULL));
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 0; i<5; i++) {
        Node<int> *newNode = new Node<int>((rand() % (20))+ 1);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    cout << head->toString() << endl;
    Node<int> *newList = partition(head,8);
    cout << newList->toString() << endl;
    
}
