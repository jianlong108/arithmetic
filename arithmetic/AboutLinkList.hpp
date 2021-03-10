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

// 指定区间内反转链表 3,5
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
//排序
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//进阶：
//你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

Node<int>* sortListHeadTail(Node<int>* head, Node<int>* tail);
Node<int>* merge(Node<int>* head1, Node<int>* head2);

// O(n*n) O(1)
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

// 插入排序: O(n*n) O(1)
Node<int>* insertionSortList(Node<int>* head)
{
    if (head == nullptr) {
        return nullptr;
    }
    Node<int> *dummpy = new Node<int>(0);
    dummpy->next = head;
    Node<int> *lastSort = head;
    Node<int> *cur = head->next;
    while (cur) {
        if (lastSort->_value < cur->_value) {
            lastSort = lastSort->next;
        } else {
            Node<int> *prev = dummpy;
            while (prev->next->_value < cur->_value) {
                prev = prev->next;
            }
            lastSort->next = cur->next;
            
            cur->next = prev->next;
            prev->next = cur;
            
        }
        
        cur = lastSort->next;
    }
    
    
    return dummpy->next;
}

void TestSortList(){
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
    Node<int> *newList = insertionSortList(head);
    cout << newList->toString() << endl;
}

/*
 给定两个用链表表示的整数，每个节点包含一个数位。

 这些数位是反向存放的，也就是个位排在链表首部。

 编写函数对这两个整数求和，并用链表形式返回结果。
 
 (7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
 输出：2 -> 1 -> 9，即912
 
 */
Node<int>* addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    Node<int> *dummyHead = new Node<int>(0);
    Node<int> *currentNode = dummyHead;
    int tmp = 0;
    while (l1 || l2) {
        int v1 = 0;
        if (l1 != nullptr) {
            v1 = l1->_value;
        }
        int v2 = 0;
        if (l2 != nullptr) {
            v2 = l2->_value;
        }
        int value = (v1 + v2 + tmp) % 10;
        tmp = (v1 + v2 + tmp)/10;
        Node<int> *newNode = new Node<int>(value);
        if (dummyHead->next == nullptr) {
            dummyHead->next = newNode;
        }
        currentNode->next = newNode;
        currentNode = newNode;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        
    }
    if (tmp > 0) {
        Node<int> *newNode = new Node<int>(tmp);
        currentNode->next = newNode;
    }
    
    return dummyHead->next;
}

void TestaddTwoNumbers(){
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 3; i<7; i++) {
        Node<int> *newNode = new Node<int>(i);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    
    
    Node<int> *head1 = NULL;
    Node<int> *tmp1 = NULL;
    for (int i = 5; i<10; i++) {
        Node<int> *newNode = new Node<int>(i);
        if (head1 == NULL) {
            head1 = newNode;
            tmp1 = newNode;
        } else {
            tmp1->next = newNode;
            tmp1 = newNode;
        }
    }
    cout << head->toString() << endl;
    cout << head1->toString() << endl;
    
    Node<int> *newList = addTwoNumbers(head, head1);
    cout << newList->toString() << endl;
}

/*
 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

 说明：不允许修改给定的链表。

 进阶：

 你是否可以使用 O(1) 空间解决此题？
 */
Node<int> *detectCycle(Node<int> *head)
{
    Node<int> *fast = head, *slow = head;
    while (true) {
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        //快指针和慢指针能相遇,说明一定存在环
        if (fast == slow) break;
    }
    //存在环的前提下,去找到环的入口结点
    /*起点到环口的距离为a,环口到相遇点的距离为b,相遇点到环口的距离为c
     相遇时,快指针走的距离为 a + n(b+c) + b 慢指针走的距离为 a+b
     快指针走过的路程永远是慢指针的两倍
     a+n(b+c)+b = 2(a+b);
     (n-1)b + nc = a
    */
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;

}

void TestdetectCycle()
{
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 3; i<9; i++) {
        Node<int> *newNode = new Node<int>(i);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    //增加一个环
//    tmp->next = head->next->next;
    
    cout << head->toString() << endl;
//    Node<int> *newList = detectCycle(head);
//    cout << newList->toString() << endl;
}

/*
 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 输入: 1->2->3->4->5->NULL, k = 2
 输出: 4->5->1->2->3->NULL
 */
Node<int>* rotateRight(Node<int>* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }
    int len = 0;
    //遍历找到最后一个结点,并得到链表的长度
    Node<int> *cur = head;
    Node<int> *lastNode = nullptr;
    while (cur) {
        len++;
        if (cur->next == nullptr) {
            lastNode = cur;
        }
        cur = cur->next;
    }
    //将单链表组合成环
    lastNode->next = head;
    //获取移动k对应的偏移量offset
    int offset = k % len;
    if (offset == 0) {
        return head;
    }
    Node<int> *dummpy = head;
    while (offset) {
        dummpy = dummpy->next;
        offset--;
    }
    //找到新的头结点
    head = dummpy;
    while (len > 1) {
        dummpy = dummpy->next;
        len--;
    }
    //断开链表
    dummpy->next = NULL;
    return head;
    
}
void TestRotateRight(){
    srand((unsigned)time(NULL));
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 0; i<5; i++) {
        Node<int> *newNode = new Node<int>((rand() % (50))+ 1);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    cout << head->toString() << endl;
    Node<int> *newList = rotateRight(head,2);
    cout << newList->toString() << endl;
}

Node<int>* oddEvenList(Node<int>* head) {
    if (head == nullptr) {
        return head;
    }
    //奇
    Node<int> *oddHead = head;
    //偶
    Node<int> *evenHead = head->next;
    Node<int> *even = evenHead;
    while (even != nullptr && even->next != nullptr) {
        oddHead->next = even->next;
        oddHead = even->next;
        
        even->next = oddHead->next;
        even = oddHead->next;
    }
    oddHead->next = evenHead;
    return head;
    
}
void TestoddEvenList(){
    srand((unsigned)time(NULL));
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 0; i<6; i++) {
        Node<int> *newNode = new Node<int>((rand() % (50))+ 1);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    cout << head->toString() << endl;
    Node<int> *newList = oddEvenList(head);
    cout << newList->toString() << endl;
}
/*
 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
 
 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
 */
Node<int>* copyRandomList(Node<int>* head) {
    if (head == nullptr) {
        return head;
    }
    Node<int> *cur = head;
    while (cur) {
        Node<int> *newNode = new Node<int>(cur->_value * 2);
        newNode->next = cur->next;
        cur->next = newNode;
        
        cur = cur->next->next;
    }
    
    Node<int> *cur_old_list = head;
    Node<int> *cur_new_list = head->next;
    Node<int> *new_head = head->next;
    
    while (cur_old_list) {
        cur_old_list->next = cur_new_list->next;
        cur_old_list = cur_new_list->next;
        
        if (cur_old_list) {
            cur_new_list->next = cur_old_list->next;
            cur_new_list = cur_old_list->next;
        }
        
    }
    
    
    return new_head;
    
}

void TestcopyRandomList(){
    srand((unsigned)time(NULL));
    Node<int> *head = NULL;
    Node<int> *tmp = NULL;
    for (int i = 0; i<6; i++) {
        Node<int> *newNode = new Node<int>((rand() % (50))+ 1);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    Node<int> *newList = copyRandomList(head);
    cout << head->toString() << endl;
    cout << newList->toString() << endl;
}
