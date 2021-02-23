//
//  链表相关.cpp
//  算法
//
//  Created by JL on 2021/2/23.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#include <stdio.h>

class ListNode {
public:
    int val;
    ListNode &next;
}


//反转链表
// 1-2-3-null  ===>  null-1-2-3

ListNode & reverseList(ListNode &head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
