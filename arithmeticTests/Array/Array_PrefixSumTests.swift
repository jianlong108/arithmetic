//
//  Array_PrefixSumTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试前缀和数组算法
///
/// 涵盖算法：
/// 1. 构建一维前缀和数组
/// 2. 查询区间和
/// 3. 构建二维前缀和矩阵
/// 4. 查询子矩阵和
final class Array_PrefixSumTests: XCTestCase {
    
    // MARK: - 一维前缀和数组
    
    func test_buildPrefix_basic() {
        let nums = [1, 2, 3, 4]
        let prefix = PreviewArray.buildPrefix(nums)
        
        XCTAssertEqual(prefix, [0, 1, 3, 6, 10], "前缀和数组应为 [0, 1, 3, 6, 10]")
    }
    
    func test_buildPrefix_singleElement() {
        let nums = [5]
        let prefix = PreviewArray.buildPrefix(nums)
        
        XCTAssertEqual(prefix, [0, 5])
    }
    
    func test_buildPrefix_emptyArray() {
        let nums: [Int] = []
        let prefix = PreviewArray.buildPrefix(nums)
        
        XCTAssertEqual(prefix, [0])
    }
    
    func test_buildPrefix_negativeNumbers() {
        let nums = [-1, 2, -3, 4]
        let prefix = PreviewArray.buildPrefix(nums)
        
        XCTAssertEqual(prefix, [0, -1, 1, -2, 2])
    }
    
    func test_buildPrefix_allZeros() {
        let nums = [0, 0, 0, 0]
        let prefix = PreviewArray.buildPrefix(nums)
        
        XCTAssertEqual(prefix, [0, 0, 0, 0, 0])
    }
    
    // MARK: - 区间和查询
    
    func test_rangeSum_basic() {
        let nums = [3, -1, 4, 2, 5]
        let prefix = PreviewArray.buildPrefix(nums)
        
        let sum0_2 = PreviewArray.rangeSum(prefix, l: 0, r: 2) // 3 + (-1) + 4 = 6
        let sum1_3 = PreviewArray.rangeSum(prefix, l: 1, r: 3) // -1 + 4 + 2 = 5
        let sum2_4 = PreviewArray.rangeSum(prefix, l: 2, r: 4) // 4 + 2 + 5 = 11
        
        XCTAssertEqual(sum0_2, 6, "[0, 2] 区间和应为 6")
        XCTAssertEqual(sum1_3, 5, "[1, 3] 区间和应为 5")
        XCTAssertEqual(sum2_4, 11, "[2, 4] 区间和应为 11")
    }
    
    func test_rangeSum_singleElement() {
        let nums = [10, 20, 30, 40]
        let prefix = PreviewArray.buildPrefix(nums)
        
        let sum1_1 = PreviewArray.rangeSum(prefix, l: 1, r: 1)
        
        XCTAssertEqual(sum1_1, 20, "单个元素区间和应为该元素值")
    }
    
    func test_rangeSum_wholeArray() {
        let nums = [1, 2, 3, 4, 5]
        let prefix = PreviewArray.buildPrefix(nums)
        
        let totalSum = PreviewArray.rangeSum(prefix, l: 0, r: 4)
        
        XCTAssertEqual(totalSum, 15, "整个数组的和应为 15")
    }
    
    func test_rangeSum_negativeResult() {
        let nums = [5, -10, 3, 2]
        let prefix = PreviewArray.buildPrefix(nums)
        
        let sum0_1 = PreviewArray.rangeSum(prefix, l: 0, r: 1) // 5 + (-10) = -5
        
        XCTAssertEqual(sum0_1, -5, "区间和可以为负数")
    }
    
    func test_rangeSum_multipleQueries() {
        let nums = [1, 3, 5, 7, 9, 11]
        let prefix = PreviewArray.buildPrefix(nums)
        
        // 多次查询应保持结果一致
        XCTAssertEqual(PreviewArray.rangeSum(prefix, l: 0, r: 2), 9)
        XCTAssertEqual(PreviewArray.rangeSum(prefix, l: 2, r: 4), 21)
        XCTAssertEqual(PreviewArray.rangeSum(prefix, l: 3, r: 5), 27)
        XCTAssertEqual(PreviewArray.rangeSum(prefix, l: 0, r: 5), 36)
    }
    
    // MARK: - 二维前缀和矩阵
    
    func test_buildPrefix2D_basic() {
        let matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        XCTAssertEqual(prefix.count, 4, "前缀和矩阵行数应为 4")
        XCTAssertEqual(prefix[0].count, 4, "前缀和矩阵列数应为 4")
        
        // 验证右下角的值（整个矩阵的和）
        XCTAssertEqual(prefix[3][3], 45, "整个矩阵的和应为 45")
    }
    
    func test_buildPrefix2D_singleElement() {
        let matrix = [[5]]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        XCTAssertEqual(prefix[1][1], 5)
    }
    
    func test_buildPrefix2D_emptyMatrix() {
        let matrix: [[Int]] = []
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        XCTAssertTrue(prefix.isEmpty || prefix[0].isEmpty)
    }
    
    func test_buildPrefix2D_rectangularMatrix() {
        let matrix = [
            [1, 2],
            [3, 4],
            [5, 6]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        XCTAssertEqual(prefix.count, 4)
        XCTAssertEqual(prefix[0].count, 3)
        XCTAssertEqual(prefix[3][2], 21, "整个矩阵和应为 21")
    }
    
    // MARK: - 子矩阵和查询
    
    func test_submatrixSum_basic() {
        let matrix = [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let sum0 = PreviewArray.submatrixSum(prefix, r1: 2, c1: 1, r2: 4, c2: 3)
        let sum1 = PreviewArray.submatrixSum(prefix, r1: 1, c1: 1, r2: 2, c2: 2)
        let sum2 = PreviewArray.submatrixSum(prefix, r1: 1, c1: 2, r2: 2, c2: 4)
        
        XCTAssertEqual(sum0, 8, "子矩阵 [2,1] -> [4,3] 的和应为 8")
        XCTAssertEqual(sum1, 11, "子矩阵 [1,1] -> [2,2] 的和应为 11")
        XCTAssertEqual(sum2, 12, "子矩阵 [1,2] -> [2,4] 的和应为 12")
    }
    
    func test_submatrixSum_singleCell() {
        let matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let cell = PreviewArray.submatrixSum(prefix, r1: 1, c1: 1, r2: 1, c2: 1)
        
        XCTAssertEqual(cell, 5, "单个单元格的和应为该单元格的值")
    }
    
    func test_submatrixSum_wholeMatrix() {
        let matrix = [
            [1, 2],
            [3, 4]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let total = PreviewArray.submatrixSum(prefix, r1: 0, c1: 0, r2: 1, c2: 1)
        
        XCTAssertEqual(total, 10, "整个矩阵的和应为 10")
    }
    
    func test_submatrixSum_firstRow() {
        let matrix = [
            [1, 2, 3],
            [4, 5, 6]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let firstRow = PreviewArray.submatrixSum(prefix, r1: 0, c1: 0, r2: 0, c2: 2)
        
        XCTAssertEqual(firstRow, 6, "第一行的和应为 6")
    }
    
    func test_submatrixSum_firstColumn() {
        let matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let firstCol = PreviewArray.submatrixSum(prefix, r1: 0, c1: 0, r2: 2, c2: 0)
        
        XCTAssertEqual(firstCol, 12, "第一列的和应为 12")
    }
    
    func test_submatrixSum_withNegatives() {
        let matrix = [
            [1, -2, 3],
            [-4, 5, -6],
            [7, -8, 9]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        let centerSum = PreviewArray.submatrixSum(prefix, r1: 1, c1: 1, r2: 1, c2: 1)
        
        XCTAssertEqual(centerSum, 5, "中心单元格值应为 5")
    }
    
    func test_submatrixSum_multipleQueries() {
        let matrix = [
            [1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12]
        ]
        let prefix = PreviewArray.buildPrefix2D(matrix)
        
        // 多次查询不同区域
        XCTAssertEqual(PreviewArray.submatrixSum(prefix, r1: 0, c1: 0, r2: 0, c2: 3), 10)
        XCTAssertEqual(PreviewArray.submatrixSum(prefix, r1: 0, c1: 0, r2: 2, c2: 0), 15)
        XCTAssertEqual(PreviewArray.submatrixSum(prefix, r1: 1, c1: 1, r2: 2, c2: 2), 44)
    }
}
