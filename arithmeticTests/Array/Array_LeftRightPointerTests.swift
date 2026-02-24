//
//  Array_LeftRightPointerTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试左右指针算法
///
/// 涵盖算法：
/// 1. 有序数组的两数之和
/// 2. 有序数组的三数之和
/// 3. 反转字符数组
/// 4. 判断回文串
/// 5. 最长回文子串
final class Array_LeftRightPointerTests: XCTestCase {
    
    // MARK: - 有序数组的两数之和
    
    func test_twoSumSorted_basic() {
        let nums = [2, 7, 11, 15]
        let result = LeftRightPointer.twoSumSorted(nums, target: 9)
        
        XCTAssertNotNil(result, "应找到解")
        XCTAssertEqual(result?.0, 1, "第一个索引应为 1 (1-based)")
        XCTAssertEqual(result?.1, 2, "第二个索引应为 2 (1-based)")
    }
    
    func test_twoSumSorted_negative() {
        let nums = [-3, -1, 0, 2, 4]
        let result = LeftRightPointer.twoSumSorted(nums, target: -1)
        
        XCTAssertNotNil(result)
        XCTAssertEqual(result?.0, 1)
        XCTAssertEqual(result?.1, 3)
    }
    
    func test_twoSumSorted_sameNumbers() {
        let nums = [1, 2, 2, 3]
        let result = LeftRightPointer.twoSumSorted(nums, target: 4)
        
        XCTAssertNotNil(result)
        XCTAssertTrue(result?.0 == 2 && result?.1 == 3, "应找到两个 2 的索引")
    }
    
    func test_twoSumSorted_noSolution() {
        let nums = [1, 2, 3, 4]
        let result = LeftRightPointer.twoSumSorted(nums, target: 10)
        
        XCTAssertNil(result, "无解时应返回 nil")
    }
    
    func test_twoSumSorted_twoElements() {
        let nums = [1, 3]
        let result = LeftRightPointer.twoSumSorted(nums, target: 4)
        
        XCTAssertNotNil(result)
        XCTAssertEqual(result?.0, 1)
        XCTAssertEqual(result?.1, 2)
    }
    
    // MARK: - 有序数组的三数之和
    
    func test_threeSumSorted_basic() {
        let nums = [-4, -1, -1, 0, 1, 2]
        let results = LeftRightPointer.threeSumSorted(nums, target: 0)
        
        XCTAssertEqual(results.count, 2, "应有 2 组解")
        // 预期解：(-1, -1, 2) 和 (-1, 0, 1)
    }
    
    func test_threeSumSorted_noDuplicates() {
        let nums = [1, 2, 3, 4, 5]
        let results = LeftRightPointer.threeSumSorted(nums, target: 6)
        
        XCTAssertEqual(results.count, 1, "应有 1 组解: (1,2,3)")
    }
    
    func test_threeSumSorted_noSolution() {
        let nums = [1, 2, 3]
        let results = LeftRightPointer.threeSumSorted(nums, target: 10)
        
        XCTAssertTrue(results.isEmpty, "无解时应返回空数组")
    }
    
    func test_threeSumSorted_allNegative() {
        let nums = [-5, -4, -3, -2, -1]
        let results = LeftRightPointer.threeSumSorted(nums, target: -12)
        
        XCTAssertEqual(results.count, 1, "应有 1 组解: (-5,-4,-3)")
    }
    
    func test_threeSumSorted_lessThanThreeElements() {
        let nums = [1, 2]
        let results = LeftRightPointer.threeSumSorted(nums, target: 3)
        
        XCTAssertTrue(results.isEmpty, "少于 3 个元素时应返回空数组")
    }
    
    // MARK: - 反转字符数组
    
    func test_reverseChars_basic() {
        var chars: [Character] = ["h", "e", "l", "l", "o"]
        LeftRightPointer.reverseChars(&chars)
        
        XCTAssertEqual(String(chars), "olleh", "应反转为 olleh")
    }
    
    func test_reverseChars_singleChar() {
        var chars: [Character] = ["a"]
        LeftRightPointer.reverseChars(&chars)
        
        XCTAssertEqual(String(chars), "a", "单字符保持不变")
    }
    
    func test_reverseChars_twoChars() {
        var chars: [Character] = ["a", "b"]
        LeftRightPointer.reverseChars(&chars)
        
        XCTAssertEqual(String(chars), "ba")
    }
    
    func test_reverseChars_evenLength() {
        var chars: [Character] = ["1", "2", "3", "4"]
        LeftRightPointer.reverseChars(&chars)
        
        XCTAssertEqual(String(chars), "4321")
    }
    
    func test_reverseChars_oddLength() {
        var chars: [Character] = ["1", "2", "3", "4", "5"]
        LeftRightPointer.reverseChars(&chars)
        
        XCTAssertEqual(String(chars), "54321")
    }
    
    // MARK: - 判断回文串
    
    func test_isPalindrome_true() {
        XCTAssertTrue(LeftRightPointer.isPalindrome("abba"))
        XCTAssertTrue(LeftRightPointer.isPalindrome("racecar"))
        XCTAssertTrue(LeftRightPointer.isPalindrome("a"))
        XCTAssertTrue(LeftRightPointer.isPalindrome("aa"))
    }
    
    func test_isPalindrome_false() {
        XCTAssertFalse(LeftRightPointer.isPalindrome("abc"))
        XCTAssertFalse(LeftRightPointer.isPalindrome("ab"))
        XCTAssertFalse(LeftRightPointer.isPalindrome("abcde"))
    }
    
    func test_isPalindrome_empty() {
        XCTAssertTrue(LeftRightPointer.isPalindrome(""), "空字符串视为回文")
    }
    
    func test_isPalindrome_chinese() {
        XCTAssertTrue(LeftRightPointer.isPalindrome("上海自来水来自海上"))
    }
    
    // MARK: - 最长回文子串
    
    func test_longestPalindrome_oddLength() {
        let s = "babad"
        let result = LeftRightPointer.longestPalindrome(s)
        
        XCTAssertTrue(result == "bab" || result == "aba", "应返回 bab 或 aba")
    }
    
    func test_longestPalindrome_evenLength() {
        let s = "cbbd"
        let result = LeftRightPointer.longestPalindrome(s)
        
        XCTAssertEqual(result, "bb")
    }
    
    func test_longestPalindrome_singleChar() {
        let s = "a"
        let result = LeftRightPointer.longestPalindrome(s)
        
        XCTAssertEqual(result, "a")
    }
    
    func test_longestPalindrome_allSame() {
        let s = "aaaa"
        let result = LeftRightPointer.longestPalindrome(s)
        
        XCTAssertEqual(result, "aaaa")
    }
    
    func test_longestPalindrome_noPalindrome() {
        let s = "abcde"
        let result = LeftRightPointer.longestPalindrome(s)
        
        // 最长回文子串应该是任意单个字符
        XCTAssertEqual(result.count, 1)
    }
    
    func test_longestPalindrome_wholeString() {
        let s = "racecar"
        let result = LeftRightPointer.longestPalindrome(s)
        
        XCTAssertEqual(result, "racecar", "整个字符串就是回文")
    }
    
    func test_longestPalindrome_multipleMaxLength() {
        let s = "abacabad"
        let result = LeftRightPointer.longestPalindrome(s)
        
        // 可能是 "aba" 或 "aca" 或 "aba" (最后一个)
        XCTAssertEqual(result.count, 3)
    }
}
