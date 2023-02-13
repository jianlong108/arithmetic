//
//  6-合并两个有序链表.hpp
//  arithmetic
//
//  Created by JL on 2023/2/12.
//  Copyright © 2023 wangjianlong. All rights reserved.
//

#ifndef _6_链表相关_h
#define _6_链表相关_h
/*
 将两个升序链表 合并成一个新的链表
 */

#include "SingleLinkList.hpp"

Node<int>* mergeSortLinkList(Node<int>* head1, Node<int>* head2) {
    /**
     当你需要创造一条新链表的时候，可以使用虚拟头结点简化边界情况的处理。

     比如说，让你把两条有序链表合并成一条新的有序链表，是不是要创造一条新链表？再比你想把一条链表分解成两条链表，是不是也在创造新链表？这些情况都可以使用虚拟头结点简化边界情况的处理。


     */
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

/**
 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

 你应当 保留 两个分区中每个节点的初始相对位置 (其实就是遍历,只有遍历才不会改变相对位置)

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/partition-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

Node<int>* partition(Node<int>* l, int x) {
    //在合并两个有序链表时让你合二为一，而这里需要分解让你把原链表一分为二。具体来说，我们可以把原链表分成两个小链表，一个链表中的元素大小都小于 x，另一个链表中的元素都大于等于 x，最后再把这两条链表接到一起，就得到了题目想要的结果
    
    // 存放小于 x 的链表的虚拟头结点
    Node<int>* dummy1 = new Node<int>(-1);
    // 存放大于等于 x 的链表的虚拟头结点
    Node<int>* dummy2 = new Node<int>(-1);
    // p1, p2 指针负责生成结果链表
    Node<int>* p1 = dummy1;
    Node<int>* p2 = dummy2;
    // p 负责遍历原链表，类似合并两个有序链表的逻辑
    // 这里是将一个链表分解成两个链表
    Node<int>* p = l;
    while (p) {
        if (p->_value < x) {
            p1->next = p;
            p1 = p1->next;
        } else {
            p2->next = p;
            p2 = p2->next;
        }
        Node<int> *tmp = p->next;
        p->next = NULL;
        p = tmp;
    }
    p1->next = dummy2->next;
    return dummy1->next;
}


Node<int>* arrayConvertLinkList(int arr[8])
{
    Node<int> *dummy = new Node<int>(-1);
    Node<int> *p = dummy;
    for (int i = 0; i < sizeof(int[8]) / sizeof(int); i++) {
        p->next = new Node<int>(arr[i]);
        p = p->next;
    }
    return dummy->next;
}

void testMergeTwoList() {
    
    cout << "testMergeTwoList  begin" << endl;
    int a[8] = {1,2,3,4,5,6,7,8};
    int b[8] = {5,6,7,8,9,10,11,12};
    Node<int> *l1 =  arrayConvertLinkList(a);
    cout << l1->toString() << endl;
    Node<int> *l2 =  arrayConvertLinkList(b);
    cout << l2->toString() << endl;
    Node<int> *l = mergeSortLinkList(l1,l2);
    cout << l->toString() << endl;
    cout << "testMergeTwoList  end" << endl;
}

void testPartitionList() {
    int a[8] = {1,5,2,7,8,6,3,0,4};
    Node<int> *l1 =  arrayConvertLinkList(a);
    
    Node<int> *l = partition(l1,4);
    std::cout << l->toString() << std::endl;
    cout << "testPartitionList  end" << endl;
}

#endif /* Header_h */
