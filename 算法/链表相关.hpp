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

//反转链表 3,5
// 1-2-3-4-5-null  ===>  1-2-5-4-3-null
Node<int>* reverseListBetween(Node<int>* list,int m, int n) {
    if (list == nullptr) {
        return list;
    }
    Node<int> *cur = list, *pre = nullptr;
    while (m>1) {
        pre = cur;
        cur = cur->next;
        m--;
        n--;
    }
    
    
    Node<int> *con = pre;
    Node<int> *tail = cur;
    while (n>0) {
        Node<int> *nextTemp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextTemp;
        n--;
    }
    if (con != nullptr) {
        con->next = pre;
    } else {
        list = pre;
    }
    tail->next = cur;
    return list;
}

void TestReverseList(){
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 1; i<7; i++) {
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
    Node<int> *newList = reverseListBetween(head,3,5);
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

Node<int>* sortListHeadTail(Node<int>* head, Node<int>* tail);
Node<int>* merge(Node<int>* head1, Node<int>* head2);

Node<int>* sortList(Node<int>* head) {
    return sortListHeadTail(head, nullptr);
}

Node<int>* sortListHeadTail(Node<int>* head, Node<int>* tail) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    Node<int>* slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        //slow走一步,fast走两步.结束时slow为中间结点
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    Node<int>* mid = slow;
    return merge(sortListHeadTail(head, mid), sortListHeadTail(mid, tail));
}

Node<int>* merge(Node<int>* head1, Node<int>* head2) {
    Node<int>* dummyHead = new Node<int>(0);
    Node<int>* temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->_value <= temp2->_value) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr) {
        temp->next = temp1;
    } else if (temp2 != nullptr) {
        temp->next = temp2;
    }
    return dummyHead->next;
}
