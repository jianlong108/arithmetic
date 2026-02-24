//
//  BubbleSort.swift
//  arithmetic
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_bubble_sort_tests")
public func run_bubble_sort_tests() {
    BubbleSort.Tests.run()
}

/*
 冒泡排序 (Bubble Sort)
 
 基本思想：
 反复遍历待排序数组，每次比较相邻两个元素，如果顺序错误就交换它们。
 每轮遍历会将当前未排序部分的最大值"冒泡"到末尾。
 
 优化：
 如果某一轮遍历中没有发生任何交换，说明数组已经有序，可以提前终止。
 
 时间复杂度：
 - 最好情况：O(n) — 数组已有序，仅需一次遍历
 - 最坏情况：O(n²) — 数组完全逆序
 - 平均情况：O(n²)
 
 空间复杂度：O(1) — 原地排序
 稳定性：稳定
 */
public enum BubbleSort {
    
    /// 冒泡排序（带提前终止优化）
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sort(_ nums: inout [Int]) {
        let n = nums.count
        guard n > 1 else { return }
        
        for i in 0..<n {
            var swapped = false
            // 每轮将未排序部分的最大值冒泡到位置 n-1-i
            for j in 0..<(n - 1 - i) {
                if nums[j] > nums[j + 1] {
                    nums.swapAt(j, j + 1)
                    swapped = true
                }
            }
            // 本轮无交换，说明已有序，提前终止
            if !swapped { break }
        }
    }
    
    // MARK: - 内置测试
    
    public enum Tests {
        public static func run() {
            // 基本排序
            var arr1 = [5, 3, 8, 4, 2]
            BubbleSort.sort(&arr1)
            assert(arr1 == [2, 3, 4, 5, 8], "基本排序失败")
            
            // 空数组
            var arr2: [Int] = []
            BubbleSort.sort(&arr2)
            assert(arr2 == [], "空数组排序失败")
            
            // 单元素
            var arr3 = [1]
            BubbleSort.sort(&arr3)
            assert(arr3 == [1], "单元素排序失败")
            
            // 已排序
            var arr4 = [1, 2, 3, 4, 5]
            BubbleSort.sort(&arr4)
            assert(arr4 == [1, 2, 3, 4, 5], "已排序数组失败")
            
            // 逆序
            var arr5 = [5, 4, 3, 2, 1]
            BubbleSort.sort(&arr5)
            assert(arr5 == [1, 2, 3, 4, 5], "逆序数组排序失败")
            
            print("✅ BubbleSort 所有内置测试通过")
        }
    }
}
