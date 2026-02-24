//
//  LinkList_AlgorithmTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试链表常用算法
///
/// 涵盖算法：
/// 1. 寻找链表倒数第 K 个节点
/// 2. 寻找链表中点
/// 3. 判断链表是否包含环并找出环起点
/// 4. 判断两个链表是否相交并找出交点
final class LinkList_AlgorithmTests: XCTestCase {
    
    // MARK: - 倒数第 K 个节点
    
    func test_kthFromEnd_basic() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 1)?.value, 5, "倒数第1个应为5")
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 2)?.value, 4, "倒数第2个应为4")
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 5)?.value, 1, "倒数第5个应为1")
    }
    
    func test_kthFromEnd_kGreaterThanLength() {
        let head = MergeSortedLists.buildList([1, 2, 3])
        
        XCTAssertNil(MergeSortedLists.kthFromEnd(head, k: 4), "k 大于链表长度应返回 nil")
        XCTAssertNil(MergeSortedLists.kthFromEnd(head, k: 10), "k 远大于链表长度应返回 nil")
    }
    
    func test_kthFromEnd_singleElement() {
        let head = MergeSortedLists.buildList([42])
        
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 1)?.value, 42)
        XCTAssertNil(MergeSortedLists.kthFromEnd(head, k: 2))
    }
    
    func test_kthFromEnd_kIsZero() {
        let head = MergeSortedLists.buildList([1, 2, 3])
        
        XCTAssertNil(MergeSortedLists.kthFromEnd(head, k: 0), "k 为 0 应返回 nil")
    }
    
    func test_kthFromEnd_emptyList() {
        let head: JLSinglyLinkNode<Int>? = nil
        
        XCTAssertNil(MergeSortedLists.kthFromEnd(head, k: 1))
    }
    
    func test_kthFromEnd_longList() {
        let head = MergeSortedLists.buildList(Array(1...100))
        
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 10)?.value, 91)
        XCTAssertEqual(MergeSortedLists.kthFromEnd(head, k: 50)?.value, 51)
    }
    
    // MARK: - 寻找链表中点
    
    func test_middleNode_oddLength() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 3, "奇数长度链表的中点应为第 3 个元素")
    }
    
    func test_middleNode_evenLength() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 3, "偶数长度链表应返回第二个中点")
    }
    
    func test_middleNode_singleElement() {
        let head = MergeSortedLists.buildList([1])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 1)
    }
    
    func test_middleNode_twoElements() {
        let head = MergeSortedLists.buildList([1, 2])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 2, "两个元素应返回第二个")
    }
    
    func test_middleNode_emptyList() {
        let head: JLSinglyLinkNode<Int>? = nil
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertNil(middle)
    }
    
    func test_middleNode_longOddList() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5, 6, 7])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 4)
    }
    
    func test_middleNode_longEvenList() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5, 6])
        let middle = MergeSortedLists.middleNode(head)
        
        XCTAssertEqual(middle?.value, 4)
    }
    
    // MARK: - 环检测
    
    func test_detectCycle_hasCycle() {
        // 创建带环链表: 1 -> 2 -> 3 -> 4 -> 5
        //                          ^         |
        //                          |_________|
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        var node = head
        var thirdNode: JLSinglyLinkNode<Int>?
        var lastNode: JLSinglyLinkNode<Int>?
        
        var index = 0
        while node != nil {
            if index == 2 { thirdNode = node }
            if node!.next == nil { lastNode = node }
            node = node!.next
            index += 1
        }
        
        // 创建环：尾节点指向第3个节点
        lastNode?.next = thirdNode
        
        let cycleStart = MergeSortedLists.detectCycleStart(head)
        
        XCTAssertTrue(cycleStart === thirdNode, "应检测到环起点为第3个节点")
        XCTAssertEqual(cycleStart?.value, 3)
    }
    
    func test_detectCycle_noCycle() {
        let head = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        let cycleStart = MergeSortedLists.detectCycleStart(head)
        
        XCTAssertNil(cycleStart, "无环链表应返回 nil")
    }
    
    func test_detectCycle_singleNodeCycle() {
        let node = JLSinglyLinkNode(1)
        node.next = node // 自环
        
        let cycleStart = MergeSortedLists.detectCycleStart(node)
        
        XCTAssertTrue(cycleStart === node, "单节点环应返回该节点")
    }
    
    func test_detectCycle_emptyList() {
        let head: JLSinglyLinkNode<Int>? = nil
        let cycleStart = MergeSortedLists.detectCycleStart(head)
        
        XCTAssertNil(cycleStart)
    }
    
    func test_detectCycle_cycleAtHead() {
        // 创建环: 1 -> 2 -> 3
        //         ^         |
        //         |_________|
        let head = MergeSortedLists.buildList([1, 2, 3])
        var node = head
        while node?.next != nil {
            node = node?.next
        }
        node?.next = head // 尾节点指向头节点
        
        let cycleStart = MergeSortedLists.detectCycleStart(head)
        
        XCTAssertTrue(cycleStart === head, "环起点应为头节点")
    }
    
    // MARK: - 链表相交
    
    func test_intersection_hasIntersection() {
        // 创建共享节点段: 7 -> 8 -> 9
        let shared = MergeSortedLists.buildList([7, 8, 9])
        
        // 链表 A: 1 -> 2 -> 3 -> shared
        let headA = MergeSortedLists.buildList([1, 2, 3])
        var tailA = headA
        while tailA?.next != nil { tailA = tailA?.next }
        tailA?.next = shared
        
        // 链表 B: 4 -> 5 -> shared
        let headB = MergeSortedLists.buildList([4, 5])
        var tailB = headB
        while tailB?.next != nil { tailB = tailB?.next }
        tailB?.next = shared
        
        let intersection = MergeSortedLists.intersectionNode(headA, headB)
        
        XCTAssertTrue(intersection === shared, "应检测到相交节点")
        XCTAssertEqual(intersection?.value, 7)
    }
    
    func test_intersection_noIntersection() {
        let headA = MergeSortedLists.buildList([1, 2, 3])
        let headB = MergeSortedLists.buildList([4, 5, 6])
        
        let intersection = MergeSortedLists.intersectionNode(headA, headB)
        
        XCTAssertNil(intersection, "不相交的链表应返回 nil")
    }
    
    func test_intersection_sameHead() {
        let head = MergeSortedLists.buildList([1, 2, 3])
        
        let intersection = MergeSortedLists.intersectionNode(head, head)
        
        XCTAssertTrue(intersection === head, "相同链表的交点应为头节点")
    }
    
    func test_intersection_differentLengths() {
        let shared = MergeSortedLists.buildList([100])
        
        let headA = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        var tailA = headA
        while tailA?.next != nil { tailA = tailA?.next }
        tailA?.next = shared
        
        let headB = MergeSortedLists.buildList([10])
        var tailB = headB
        while tailB?.next != nil { tailB = tailB?.next }
        tailB?.next = shared
        
        let intersection = MergeSortedLists.intersectionNode(headA, headB)
        
        XCTAssertTrue(intersection === shared, "不同长度链表应能找到交点")
    }
    
    func test_intersection_oneEmpty() {
        let headA = MergeSortedLists.buildList([1, 2, 3])
        let headB: JLSinglyLinkNode<Int>? = nil
        
        let intersection = MergeSortedLists.intersectionNode(headA, headB)
        
        XCTAssertNil(intersection, "一个链表为空时无交点")
    }
    
    func test_intersection_bothEmpty() {
        let headA: JLSinglyLinkNode<Int>? = nil
        let headB: JLSinglyLinkNode<Int>? = nil
        
        let intersection = MergeSortedLists.intersectionNode(headA, headB)
        
        XCTAssertNil(intersection)
    }
}
