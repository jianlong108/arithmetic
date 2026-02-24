//
//  Array_FastSlowPointerTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试快慢指针算法
/// 
/// 涵盖算法：
/// 1. 删除排序数组中的重复元素
/// 2. 移除数组中等于指定值的元素
/// 3. 将所有 0 移到数组末尾
final class Array_FastSlowPointerTests: XCTestCase {
    
    // MARK: - 删除排序数组中的重复元素
    
    func test_removeDuplicates_basic() {
        var nums = [1, 1, 2]
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 2, "新长度应为 2")
        XCTAssertEqual(Array(nums[0..<newLength]), [1, 2], "前 2 个元素应为 [1, 2]")
    }
    
    func test_removeDuplicates_multipleDuplicates() {
        var nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 5, "新长度应为 5")
        XCTAssertEqual(Array(nums[0..<newLength]), [0, 1, 2, 3, 4], "应保留 5 个唯一元素")
    }
    
    func test_removeDuplicates_singleElement() {
        var nums = [1]
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 1, "单元素数组长度应为 1")
        XCTAssertEqual(nums[0], 1)
    }
    
    func test_removeDuplicates_emptyArray() {
        var nums: [Int] = []
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 0, "空数组长度应为 0")
    }
    
    func test_removeDuplicates_noDuplicates() {
        var nums = [1, 2, 3, 4, 5]
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 5, "无重复元素时长度不变")
        XCTAssertEqual(Array(nums[0..<newLength]), [1, 2, 3, 4, 5])
    }
    
    func test_removeDuplicates_allSame() {
        var nums = [2, 2, 2, 2, 2]
        let newLength = FastSlowPointer.removeDuplicates(&nums)
        
        XCTAssertEqual(newLength, 1, "全部相同时应返回 1")
        XCTAssertEqual(nums[0], 2)
    }
    
    // MARK: - 移除指定值的元素
    
    func test_removeElement_basic() {
        var nums = [3, 2, 2, 3]
        let newLength = FastSlowPointer.removeElement(&nums, 3)
        
        XCTAssertEqual(newLength, 2, "移除 3 后应剩余 2 个元素")
        XCTAssertTrue(Set(nums[0..<newLength]).isSubset(of: [2]), "剩余元素应为 2")
    }
    
    func test_removeElement_multipleOccurrences() {
        var nums = [0, 1, 2, 2, 3, 0, 4, 2]
        let newLength = FastSlowPointer.removeElement(&nums, 2)
        
        XCTAssertEqual(newLength, 5, "移除所有 2 后应剩余 5 个元素")
        let remaining = Array(nums[0..<newLength])
        XCTAssertFalse(remaining.contains(2), "结果中不应包含 2")
    }
    
    func test_removeElement_noMatch() {
        var nums = [1, 2, 3, 4]
        let newLength = FastSlowPointer.removeElement(&nums, 5)
        
        XCTAssertEqual(newLength, 4, "没有匹配值时长度不变")
    }
    
    func test_removeElement_removeAll() {
        var nums = [1, 1, 1, 1]
        let newLength = FastSlowPointer.removeElement(&nums, 1)
        
        XCTAssertEqual(newLength, 0, "移除所有元素后长度为 0")
    }
    
    func test_removeElement_emptyArray() {
        var nums: [Int] = []
        let newLength = FastSlowPointer.removeElement(&nums, 1)
        
        XCTAssertEqual(newLength, 0, "空数组移除后仍为空")
    }
    
    // MARK: - 移动零到数组末尾
    
    func test_moveZeroes_basic() {
        var nums = [0, 1, 0, 3, 12]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [1, 3, 12, 0, 0], "非零元素应保持相对顺序，零移到末尾")
    }
    
    func test_moveZeroes_noZeros() {
        var nums = [4, 5, 6]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [4, 5, 6], "无零时数组不变")
    }
    
    func test_moveZeroes_allZeros() {
        var nums = [0, 0, 0, 0]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [0, 0, 0, 0], "全为零时数组不变")
    }
    
    func test_moveZeroes_singleElement() {
        var nums = [0]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [0], "单个零保持不变")
    }
    
    func test_moveZeroes_zerosAtEnd() {
        var nums = [1, 2, 3, 0, 0]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [1, 2, 3, 0, 0], "零已在末尾时数组不变")
    }
    
    func test_moveZeroes_zerosAtBeginning() {
        var nums = [0, 0, 1, 2, 3]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [1, 2, 3, 0, 0], "零在开头时应移到末尾")
    }
    
    func test_moveZeroes_alternatingZeros() {
        var nums = [0, 1, 0, 2, 0, 3]
        FastSlowPointer.moveZeroes(&nums)
        
        XCTAssertEqual(nums, [1, 2, 3, 0, 0, 0], "交替出现的零应全部移到末尾")
    }
}
