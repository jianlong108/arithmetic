//
//  链表相关.cpp
//  算法
//
//  Created by JL on 2021/2/23.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkList.hpp"

//反转链表
// 1-2-3-null  ===>  null-1-2-3

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
