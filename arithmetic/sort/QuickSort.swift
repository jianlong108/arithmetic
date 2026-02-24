//
//  QuickSort.swift
//  arithmetic
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_quick_sort_tests")
public func run_quick_sort_tests() {
    QuickSort.Tests.run()
}

/*
 快速排序 (Quick Sort)
 
 基本思想：
 采用分治法（Divide and Conquer）策略：
 1. 选择一个基准元素（pivot）
 2. 分区（Partition）：将数组分为两部分，左边都小于等于 pivot，右边都大于等于 pivot
 3. 递归：对左右两部分分别递归排序
 
 Pivot 选择策略：
 - 固定选取第一个/最后一个元素：简单但在已排序数组上退化为 O(n²)
 - 随机选取：避免最坏情况
 - 三数取中：取首、中、尾三个元素的中位数，兼顾性能和稳定性
 
 分区方案：
 - Lomuto 分区：单指针从左到右扫描，实现简单
 - Hoare 分区：双指针从两端向中间扫描，交换次数更少
 
 时间复杂度：
 - 最好情况：O(n log n) — 每次 pivot 恰好在中间
 - 最坏情况：O(n²) — 每次 pivot 是最大或最小值
 - 平均情况：O(n log n)
 
 空间复杂度：O(log n) — 递归栈空间
 稳定性：不稳定
 
 适用场景：
 - 通用排序场景，实际中效率最高的比较排序之一
 - 不需要稳定性的场景
 */
public enum QuickSort {
    
    /// 快速排序（随机 pivot + Lomuto 分区）
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sort(_ nums: inout [Int]) {
        guard nums.count > 1 else { return }
        quickSort(&nums, 0, nums.count - 1)
    }
    
    /// 快速排序（Hoare 双指针分区）
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sortHoare(_ nums: inout [Int]) {
        guard nums.count > 1 else { return }
        quickSortHoare(&nums, 0, nums.count - 1)
    }
    
    // MARK: - Lomuto 分区方案
    
    private static func quickSort(_ nums: inout [Int], _ lo: Int, _ hi: Int) {
        guard lo < hi else { return }
        
        let pivotIndex = partition(&nums, lo, hi)
        quickSort(&nums, lo, pivotIndex - 1)
        quickSort(&nums, pivotIndex + 1, hi)
    }
    
    /// Lomuto 分区：选择随机 pivot，将小于 pivot 的元素放到左边
    private static func partition(_ nums: inout [Int], _ lo: Int, _ hi: Int) -> Int {
        // 随机选择 pivot，避免最坏情况
        let randomIndex = Int.random(in: lo...hi)
        nums.swapAt(randomIndex, hi)
        
        let pivot = nums[hi]
        var i = lo // i 指向下一个小于 pivot 的元素应放的位置
        
        for j in lo..<hi {
            if nums[j] <= pivot {
                nums.swapAt(i, j)
                i += 1
            }
        }
        nums.swapAt(i, hi)
        return i
    }
    
    // MARK: - Hoare 分区方案
    
    private static func quickSortHoare(_ nums: inout [Int], _ lo: Int, _ hi: Int) {
        guard lo < hi else { return }
        
        let p = hoarePartition(&nums, lo, hi)
        quickSortHoare(&nums, lo, p)
        quickSortHoare(&nums, p + 1, hi)
    }
    
    /// Hoare 分区：双指针从两端向中间扫描
    private static func hoarePartition(_ nums: inout [Int], _ lo: Int, _ hi: Int) -> Int {
        // 三数取中选 pivot
        let mid = lo + (hi - lo) / 2
        if nums[lo] > nums[mid] { nums.swapAt(lo, mid) }
        if nums[lo] > nums[hi] { nums.swapAt(lo, hi) }
        if nums[mid] > nums[hi] { nums.swapAt(mid, hi) }
        let pivot = nums[mid]
        
        var i = lo - 1
        var j = hi + 1
        
        while true {
            repeat { i += 1 } while nums[i] < pivot
            repeat { j -= 1 } while nums[j] > pivot
            
            if i >= j { return j }
            nums.swapAt(i, j)
        }
    }
    
    // MARK: - 内置测试
    
    public enum Tests {
        public static func run() {
            // Lomuto 分区
            var arr1 = [5, 3, 8, 4, 2]
            QuickSort.sort(&arr1)
            assert(arr1 == [2, 3, 4, 5, 8], "Lomuto 基本排序失败")
            
            var arr2: [Int] = []
            QuickSort.sort(&arr2)
            assert(arr2 == [], "空数组排序失败")
            
            var arr3 = [5, 4, 3, 2, 1]
            QuickSort.sort(&arr3)
            assert(arr3 == [1, 2, 3, 4, 5], "逆序排序失败")
            
            // Hoare 分区
            var arr4 = [3, 1, 4, 1, 5, 9, 2, 6]
            QuickSort.sortHoare(&arr4)
            assert(arr4 == [1, 1, 2, 3, 4, 5, 6, 9], "Hoare 含重复排序失败")
            
            var arr5 = [7, 7, 7, 7]
            QuickSort.sortHoare(&arr5)
            assert(arr5 == [7, 7, 7, 7], "全相同元素排序失败")
            
            print("✅ QuickSort 所有内置测试通过")
        }
    }
}
