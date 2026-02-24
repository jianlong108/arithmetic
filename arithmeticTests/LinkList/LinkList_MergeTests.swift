//
//  LinkList_MergeTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试链表合并算法
///
/// 涵盖算法：
/// 1. 合并两个有序链表
/// 2. 合并 K 个有序链表
final class LinkList_MergeTests: XCTestCase {
    
    // MARK: - 合并两个有序链表
    
    func test_mergeTwoLists_basic() {
        let l1 = MergeSortedLists.buildList([1, 2, 4])
        let l2 = MergeSortedLists.buildList([1, 3, 4])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 1, 2, 3, 4, 4])
    }
    
    func test_mergeTwoLists_oneEmpty() {
        let l1 = MergeSortedLists.buildList([0, 2, 5])
        let merged = MergeSortedLists.merge(l1, nil)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [0, 2, 5])
    }
    
    func test_mergeTwoLists_bothEmpty() {
        let merged = MergeSortedLists.merge(nil as JLSinglyLinkNode<Int>?, nil)
        
        XCTAssertNil(merged)
    }
    
    func test_mergeTwoLists_singleElement() {
        let l1 = MergeSortedLists.buildList([1])
        let l2 = MergeSortedLists.buildList([2])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 2])
    }
    
    func test_mergeTwoLists_differentLengths() {
        let l1 = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        let l2 = MergeSortedLists.buildList([6, 7])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 2, 3, 4, 5, 6, 7])
    }
    
    func test_mergeTwoLists_allSameValues() {
        let l1 = MergeSortedLists.buildList([1, 1, 1])
        let l2 = MergeSortedLists.buildList([1, 1])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 1, 1, 1, 1])
    }
    
    func test_mergeTwoLists_noOverlap() {
        let l1 = MergeSortedLists.buildList([1, 2, 3])
        let l2 = MergeSortedLists.buildList([4, 5, 6])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 2, 3, 4, 5, 6])
    }
    
    func test_mergeTwoLists_negativeNumbers() {
        let l1 = MergeSortedLists.buildList([-5, -1, 0])
        let l2 = MergeSortedLists.buildList([-3, 2, 4])
        let merged = MergeSortedLists.merge(l1, l2)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [-5, -3, -1, 0, 2, 4])
    }
    
    // MARK: - 合并 K 个有序链表
    
    func test_mergeKLists_basic() {
        let a = MergeSortedLists.buildList([1, 4, 5])
        let b = MergeSortedLists.buildList([1, 3, 4])
        let c = MergeSortedLists.buildList([2, 6])
        let merged = MergeSortedLists.mergeK([a, b, c])
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 1, 2, 3, 4, 4, 5, 6])
    }
    
    func test_mergeKLists_withEmptyLists() {
        let a = MergeSortedLists.buildList([0])
        let merged = MergeSortedLists.mergeK([a, nil, nil])
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [0])
    }
    
    func test_mergeKLists_allEmpty() {
        let lists: [JLSinglyLinkNode<Int>?] = [nil, nil, nil]
        let merged = MergeSortedLists.mergeK(lists)
        
        XCTAssertTrue(MergeSortedLists.toArray(merged).isEmpty)
    }
    
    func test_mergeKLists_singleList() {
        let a = MergeSortedLists.buildList([1, 2, 3, 4, 5])
        let merged = MergeSortedLists.mergeK([a])
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 2, 3, 4, 5])
    }
    
    func test_mergeKLists_manyLists() {
        let lists = [
            MergeSortedLists.buildList([1, 4, 7]),
            MergeSortedLists.buildList([2, 5, 8]),
            MergeSortedLists.buildList([3, 6, 9]),
            MergeSortedLists.buildList([0, 10])
        ]
        let merged = MergeSortedLists.mergeK(lists)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    }
    
    func test_mergeKLists_differentLengths() {
        let lists = [
            MergeSortedLists.buildList([1]),
            MergeSortedLists.buildList([2, 3]),
            MergeSortedLists.buildList([4, 5, 6]),
            MergeSortedLists.buildList([7, 8, 9, 10])
        ]
        let merged = MergeSortedLists.mergeK(lists)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    }
    
    func test_mergeKLists_duplicateValues() {
        let lists = [
            MergeSortedLists.buildList([1, 1, 1]),
            MergeSortedLists.buildList([1, 1]),
            MergeSortedLists.buildList([1])
        ]
        let merged = MergeSortedLists.mergeK(lists)
        
        XCTAssertEqual(MergeSortedLists.toArray(merged), [1, 1, 1, 1, 1, 1])
    }
}
