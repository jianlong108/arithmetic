//
//  InsertionSort.swift
//  arithmetic
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_insertion_sort_tests")
public func run_insertion_sort_tests() {
    InsertionSort.Tests.run()
}

/*
 插入排序 (Insertion Sort)
 
 基本思想：
 将数组分为已排序和未排序两部分。从第二个元素开始，每次取出一个未排序元素，
 在已排序部分从后往前比较，找到合适的位置插入。
 
 类似于打扑克牌时整理手牌的过程：
 每次摸到一张新牌，从右向左找到合适的位置插入。
 
 时间复杂度：
 - 最好情况：O(n) — 数组已有序
 - 最坏情况：O(n²) — 数组完全逆序
 - 平均情况：O(n²)
 
 空间复杂度：O(1) — 原地排序
 稳定性：稳定
 
 适用场景：
 - 小规模数据
 - 数据基本有序时效率很高
 - 常作为高级排序算法（如快排、归并）的小规模子问题处理方法
 */
public enum InsertionSort {
    
    /// 插入排序
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sort(_ nums: inout [Int]) {
        let n = nums.count
        guard n > 1 else { return }
        
        for i in 1..<n {
            let key = nums[i]
            var j = i - 1
            // 将比 key 大的元素逐个后移
            while j >= 0 && nums[j] > key {
                nums[j + 1] = nums[j]
                j -= 1
            }
            nums[j + 1] = key
        }
    }
    
    /// 二分插入排序（优化查找插入位置的过程）
    /// - Parameter nums: 待排序数组（原地修改）
    public static func binaryInsertionSort(_ nums: inout [Int]) {
        let n = nums.count
        guard n > 1 else { return }
        
        for i in 1..<n {
            let key = nums[i]
            // 用二分查找确定插入位置
            var lo = 0, hi = i
            while lo < hi {
                let mid = lo + (hi - lo) / 2
                if nums[mid] > key {
                    hi = mid
                } else {
                    lo = mid + 1
                }
            }
            // 将 [lo, i-1] 的元素后移一位
            var j = i
            while j > lo {
                nums[j] = nums[j - 1]
                j -= 1
            }
            nums[lo] = key
        }
    }
    
    // MARK: - 内置测试
    
    public enum Tests {
        public static func run() {
            var arr1 = [5, 3, 8, 4, 2]
            InsertionSort.sort(&arr1)
            assert(arr1 == [2, 3, 4, 5, 8], "基本排序失败")
            
            var arr2: [Int] = []
            InsertionSort.sort(&arr2)
            assert(arr2 == [], "空数组排序失败")
            
            var arr3 = [5, 4, 3, 2, 1]
            InsertionSort.sort(&arr3)
            assert(arr3 == [1, 2, 3, 4, 5], "逆序数组排序失败")
            
            // 二分插入排序
            var arr4 = [3, 1, 4, 1, 5, 9, 2, 6]
            InsertionSort.binaryInsertionSort(&arr4)
            assert(arr4 == [1, 1, 2, 3, 4, 5, 6, 9], "二分插入排序失败")
            
            print("✅ InsertionSort 所有内置测试通过")
        }
    }
}
