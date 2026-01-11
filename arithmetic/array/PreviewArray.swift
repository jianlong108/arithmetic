//
//  PreviewArray.swift
//  arithmetic
//
//  Created by JL on 2026/1/9.
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

// 这是前缀和 数组的代码文件
@_cdecl("run_preview_array_tests")
public func run_preview_array_tests() {
    PreviewArray.Tests.run()
}
// 前缀和数组: 输入一个整数数组,返回其前缀和数组.
// 应用算法题:
// 1. 计算数组区间内元素的和,多次查询时效率更高.
// 2. 计算二维矩阵的子矩阵和.
public enum PreviewArray {
    // 构建前缀和数组 prefix，其中 prefix[i] 表示 nums[0...i-1] 的和，prefix[0] = 0。
    public static func buildPrefix(_ nums: [Int]) -> [Int] {
        var prefix = Array(repeating: 0, count: nums.count + 1)
        for i in 0..<nums.count {
            prefix[i + 1] = prefix[i] + nums[i]
        }
        return prefix
    }

    // 查询闭区间 [l, r] 的区间和，假定 0 <= l <= r < nums.count。
    public static func rangeSum(_ prefix: [Int], l: Int, r: Int) -> Int {
        // prefix 长度比原数组多 1，索引安全由调用方保证。
        return prefix[r + 1] - prefix[l]
    }

    // 构建二维前缀和矩阵 prefix，其中 prefix[i+1][j+1] 表示 matrix[0...i][0...j] 的元素和。
    public static func buildPrefix2D(_ matrix: [[Int]]) -> [[Int]] {
        guard let cols = matrix.first?.count else { return [[Int]]() }
        let rows = matrix.count
        var prefix = Array(repeating: Array(repeating: 0, count: cols + 1), count: rows + 1)
        for i in 0..<rows {
            for j in 0..<cols {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + matrix[i][j]
            }
        }
        return prefix
    }

    // 查询子矩阵 [r1, r2] x [c1, c2]（闭区间）的元素和，基于二维前缀和。
    public static func submatrixSum(_ prefix: [[Int]], r1: Int, c1: Int, r2: Int, c2: Int) -> Int {
        // 调用方保证 0 <= r1 <= r2 < rows, 0 <= c1 <= c2 < cols。
        let a = prefix[r2 + 1][c2 + 1]
        let b = prefix[r1][c2 + 1]
        let c = prefix[r2 + 1][c1]
        let d = prefix[r1][c1]
        return a - b - c + d
    }

    public enum Tests {
        public static func run() {
            testPrefixBuild()
            testRangeSumQueries()
            testPrefix2D()
        }

        private static func testPrefixBuild() {
            let nums = [1, 2, 3, 4]
            let prefix = buildPrefix(nums)
            print("buildPrefix ->", prefix)
            assert(prefix == [0, 1, 3, 6, 10])
        }

        private static func testRangeSumQueries() {
            let nums = [3, -1, 4, 2, 5]
            let prefix = buildPrefix(nums)
            let sum0_2 = rangeSum(prefix, l: 0, r: 2) // 3 + (-1) + 4 = 6
            let sum1_3 = rangeSum(prefix, l: 1, r: 3) // -1 + 4 + 2 = 5
            let sum2_4 = rangeSum(prefix, l: 2, r: 4) // 4 + 2 + 5 = 11
            print("rangeSum ->", sum0_2, sum1_3, sum2_4)
            assert(sum0_2 == 6)
            assert(sum1_3 == 5)
            assert(sum2_4 == 11)
        }

        private static func testPrefix2D() {
            let matrix = [
                [3, 0, 1, 4, 2],
                [5, 6, 3, 2, 1],
                [1, 2, 0, 1, 5],
                [4, 1, 0, 1, 7],
                [1, 0, 3, 0, 5]
            ]
            let prefix = buildPrefix2D(matrix)
            let sum0 = submatrixSum(prefix, r1: 2, c1: 1, r2: 4, c2: 3) // expected 8
            let sum1 = submatrixSum(prefix, r1: 1, c1: 1, r2: 2, c2: 2) // 11
            let sum2 = submatrixSum(prefix, r1: 1, c1: 2, r2: 2, c2: 4) // 12
            print("submatrixSum ->", sum0, sum1, sum2)
            assert(sum0 == 8)
            assert(sum1 == 11)
            assert(sum2 == 12)
        }
    }
}