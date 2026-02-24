//
//  Sort_AlgorithmTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 排序算法单元测试
///
/// 涵盖算法：
/// 1. 冒泡排序 (BubbleSort)
/// 2. 插入排序 (InsertionSort)
/// 3. 归并排序 (MergeSort)
/// 4. 快速排序 (QuickSort)
/// 5. 堆排序 (HeapSort)
final class Sort_AlgorithmTests: XCTestCase {
    
    // MARK: - 通用测试数据
    
    /// 排序测试用例结构体
    private struct SortTestCase {
        let name: String
        let input: [Int]
        let expected: [Int]
    }
    
    /// 通用测试用例集
    private var testCases: [SortTestCase] {
        [
            SortTestCase(name: "空数组", input: [], expected: []),
            SortTestCase(name: "单元素", input: [1], expected: [1]),
            SortTestCase(name: "两个元素-有序", input: [1, 2], expected: [1, 2]),
            SortTestCase(name: "两个元素-逆序", input: [2, 1], expected: [1, 2]),
            SortTestCase(name: "已排序", input: [1, 2, 3, 4, 5], expected: [1, 2, 3, 4, 5]),
            SortTestCase(name: "逆序", input: [5, 4, 3, 2, 1], expected: [1, 2, 3, 4, 5]),
            SortTestCase(name: "含重复元素", input: [3, 1, 4, 1, 5, 9, 2, 6], expected: [1, 1, 2, 3, 4, 5, 6, 9]),
            SortTestCase(name: "全部相同", input: [7, 7, 7, 7], expected: [7, 7, 7, 7]),
            SortTestCase(name: "含负数", input: [-3, 0, 2, -1, 5], expected: [-3, -1, 0, 2, 5]),
            SortTestCase(name: "大范围数据", input: [100, -50, 0, 33, -99, 42, 1], expected: [-99, -50, 0, 1, 33, 42, 100]),
        ]
    }
    
    // MARK: - 冒泡排序
    
    func test_bubbleSort_emptyArray() {
        var nums: [Int] = []
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [], "空数组排序后应为空")
    }
    
    func test_bubbleSort_singleElement() {
        var nums = [42]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [42], "单元素数组排序后应不变")
    }
    
    func test_bubbleSort_alreadySorted() {
        var nums = [1, 2, 3, 4, 5]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "已排序数组应保持不变")
    }
    
    func test_bubbleSort_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "逆序数组应正确排序")
    }
    
    func test_bubbleSort_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素应正确排序")
    }
    
    func test_bubbleSort_allSame() {
        var nums = [7, 7, 7, 7]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [7, 7, 7, 7], "全相同元素应保持不变")
    }
    
    func test_bubbleSort_withNegatives() {
        var nums = [-3, 0, 2, -1, 5]
        BubbleSort.sort(&nums)
        XCTAssertEqual(nums, [-3, -1, 0, 2, 5], "含负数应正确排序")
    }
    
    // MARK: - 插入排序
    
    func test_insertionSort_emptyArray() {
        var nums: [Int] = []
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [], "空数组排序后应为空")
    }
    
    func test_insertionSort_singleElement() {
        var nums = [42]
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [42], "单元素数组排序后应不变")
    }
    
    func test_insertionSort_alreadySorted() {
        var nums = [1, 2, 3, 4, 5]
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "已排序数组应保持不变")
    }
    
    func test_insertionSort_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "逆序数组应正确排序")
    }
    
    func test_insertionSort_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素应正确排序")
    }
    
    func test_insertionSort_withNegatives() {
        var nums = [-3, 0, 2, -1, 5]
        InsertionSort.sort(&nums)
        XCTAssertEqual(nums, [-3, -1, 0, 2, 5], "含负数应正确排序")
    }
    
    func test_insertionSort_binaryVersion() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        InsertionSort.binaryInsertionSort(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "二分插入排序应正确排序")
    }
    
    func test_insertionSort_binaryVersion_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        InsertionSort.binaryInsertionSort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "二分插入排序逆序应正确排序")
    }
    
    // MARK: - 归并排序（纯函数版本）
    
    func test_mergeSort_emptyArray() {
        let result = MergeSort.sort([])
        XCTAssertEqual(result, [], "空数组排序后应为空")
    }
    
    func test_mergeSort_singleElement() {
        let result = MergeSort.sort([42])
        XCTAssertEqual(result, [42], "单元素数组排序后应不变")
    }
    
    func test_mergeSort_alreadySorted() {
        let result = MergeSort.sort([1, 2, 3, 4, 5])
        XCTAssertEqual(result, [1, 2, 3, 4, 5], "已排序数组应保持不变")
    }
    
    func test_mergeSort_reverseOrder() {
        let result = MergeSort.sort([5, 4, 3, 2, 1])
        XCTAssertEqual(result, [1, 2, 3, 4, 5], "逆序数组应正确排序")
    }
    
    func test_mergeSort_withDuplicates() {
        let result = MergeSort.sort([3, 1, 4, 1, 5, 9, 2, 6])
        XCTAssertEqual(result, [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素应正确排序")
    }
    
    func test_mergeSort_withNegatives() {
        let result = MergeSort.sort([-3, 0, 2, -1, 5])
        XCTAssertEqual(result, [-3, -1, 0, 2, 5], "含负数应正确排序")
    }
    
    func test_mergeSort_doesNotModifyOriginal() {
        let original = [5, 3, 1, 4, 2]
        let sorted = MergeSort.sort(original)
        XCTAssertEqual(original, [5, 3, 1, 4, 2], "纯函数版本不应修改原数组")
        XCTAssertEqual(sorted, [1, 2, 3, 4, 5], "应返回排序后的新数组")
    }
    
    // MARK: - 归并排序（原地版本）
    
    func test_mergeSortInPlace_emptyArray() {
        var nums: [Int] = []
        MergeSort.sortInPlace(&nums)
        XCTAssertEqual(nums, [], "空数组排序后应为空")
    }
    
    func test_mergeSortInPlace_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        MergeSort.sortInPlace(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "原地逆序排序应正确")
    }
    
    func test_mergeSortInPlace_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        MergeSort.sortInPlace(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "原地含重复元素应正确排序")
    }
    
    func test_mergeSortInPlace_withNegatives() {
        var nums = [-3, 0, 2, -1, 5]
        MergeSort.sortInPlace(&nums)
        XCTAssertEqual(nums, [-3, -1, 0, 2, 5], "原地含负数应正确排序")
    }
    
    // MARK: - 快速排序（Lomuto 分区）
    
    func test_quickSort_emptyArray() {
        var nums: [Int] = []
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [], "空数组排序后应为空")
    }
    
    func test_quickSort_singleElement() {
        var nums = [42]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [42], "单元素数组排序后应不变")
    }
    
    func test_quickSort_alreadySorted() {
        var nums = [1, 2, 3, 4, 5]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "已排序数组应保持不变")
    }
    
    func test_quickSort_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "逆序数组应正确排序")
    }
    
    func test_quickSort_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素应正确排序")
    }
    
    func test_quickSort_allSame() {
        var nums = [7, 7, 7, 7]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [7, 7, 7, 7], "全相同元素应保持不变")
    }
    
    func test_quickSort_withNegatives() {
        var nums = [-3, 0, 2, -1, 5]
        QuickSort.sort(&nums)
        XCTAssertEqual(nums, [-3, -1, 0, 2, 5], "含负数应正确排序")
    }
    
    // MARK: - 快速排序（Hoare 分区）
    
    func test_quickSortHoare_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        QuickSort.sortHoare(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "Hoare 逆序排序应正确")
    }
    
    func test_quickSortHoare_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        QuickSort.sortHoare(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "Hoare 含重复元素应正确排序")
    }
    
    func test_quickSortHoare_allSame() {
        var nums = [7, 7, 7, 7]
        QuickSort.sortHoare(&nums)
        XCTAssertEqual(nums, [7, 7, 7, 7], "Hoare 全相同元素应保持不变")
    }
    
    func test_quickSortHoare_withNegatives() {
        var nums = [100, -50, 0, 33, -99, 42, 1]
        QuickSort.sortHoare(&nums)
        XCTAssertEqual(nums, [-99, -50, 0, 1, 33, 42, 100], "Hoare 大范围数据应正确排序")
    }
    
    // MARK: - 堆排序
    
    func test_heapSort_emptyArray() {
        var nums: [Int] = []
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [], "空数组排序后应为空")
    }
    
    func test_heapSort_singleElement() {
        var nums = [42]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [42], "单元素数组排序后应不变")
    }
    
    func test_heapSort_alreadySorted() {
        var nums = [1, 2, 3, 4, 5]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "已排序数组应保持不变")
    }
    
    func test_heapSort_reverseOrder() {
        var nums = [5, 4, 3, 2, 1]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [1, 2, 3, 4, 5], "逆序数组应正确排序")
    }
    
    func test_heapSort_withDuplicates() {
        var nums = [3, 1, 4, 1, 5, 9, 2, 6]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素应正确排序")
    }
    
    func test_heapSort_allSame() {
        var nums = [7, 7, 7, 7]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [7, 7, 7, 7], "全相同元素应保持不变")
    }
    
    func test_heapSort_withNegatives() {
        var nums = [-3, 0, 2, -1, 5]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [-3, -1, 0, 2, 5], "含负数应正确排序")
    }
    
    func test_heapSort_largeRange() {
        var nums = [100, -50, 0, 33, -99, 42, 1]
        HeapSort.sort(&nums)
        XCTAssertEqual(nums, [-99, -50, 0, 1, 33, 42, 100], "大范围数据应正确排序")
    }
    
    // MARK: - 综合对比测试
    
    /// 验证所有排序算法对同一输入产生相同结果
    func test_allSorts_produceConsistentResults() {
        for testCase in testCases {
            // 冒泡排序
            var bubbleNums = testCase.input
            BubbleSort.sort(&bubbleNums)
            XCTAssertEqual(bubbleNums, testCase.expected, "冒泡排序 - \(testCase.name) 失败")
            
            // 插入排序
            var insertionNums = testCase.input
            InsertionSort.sort(&insertionNums)
            XCTAssertEqual(insertionNums, testCase.expected, "插入排序 - \(testCase.name) 失败")
            
            // 二分插入排序
            var binaryInsertionNums = testCase.input
            InsertionSort.binaryInsertionSort(&binaryInsertionNums)
            XCTAssertEqual(binaryInsertionNums, testCase.expected, "二分插入排序 - \(testCase.name) 失败")
            
            // 归并排序（纯函数版本）
            let mergeResult = MergeSort.sort(testCase.input)
            XCTAssertEqual(mergeResult, testCase.expected, "归并排序 - \(testCase.name) 失败")
            
            // 归并排序（原地版本）
            var mergeInPlaceNums = testCase.input
            MergeSort.sortInPlace(&mergeInPlaceNums)
            XCTAssertEqual(mergeInPlaceNums, testCase.expected, "归并原地排序 - \(testCase.name) 失败")
            
            // 快速排序（Lomuto）
            var quickNums = testCase.input
            QuickSort.sort(&quickNums)
            XCTAssertEqual(quickNums, testCase.expected, "快速排序 - \(testCase.name) 失败")
            
            // 快速排序（Hoare）— 跳过空数组和单元素（Hoare 分区需要至少 2 个元素调用 sortHoare）
            if testCase.input.count >= 2 {
                var quickHoareNums = testCase.input
                QuickSort.sortHoare(&quickHoareNums)
                XCTAssertEqual(quickHoareNums, testCase.expected, "快速排序Hoare - \(testCase.name) 失败")
            }
            
            // 堆排序
            var heapNums = testCase.input
            HeapSort.sort(&heapNums)
            XCTAssertEqual(heapNums, testCase.expected, "堆排序 - \(testCase.name) 失败")
        }
    }
}
