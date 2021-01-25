//
//  2- 两数相加.hpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#ifndef ________hpp
#define ________hpp

#include <stdio.h>

/*
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
 示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    ListNode *sumNode = new ListNode(0);
    ListNode *headNode = sumNode;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10; // 十位数 保留高位数
        sumNode->next = new ListNode(sum%10);//个位数 保留低位数
        sumNode = sumNode->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry > 0) {
        sumNode->next = new ListNode(carry);
    }
    return headNode->next;
}

#endif /* ________hpp */
