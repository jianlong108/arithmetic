//
//  MergeSort.swift
//  arithmetic
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_merge_sort_tests")
public func run_merge_sort_tests() {
    MergeSort.Tests.run()
}

/*
 归并排序 (Merge Sort)
 
 基本思想：
 采用分治法（Divide and Conquer）策略：
 1. 分解：将数组从中间分成两个子数组
 2. 递归：对两个子数组分别递归排序
 3. 合并：将两个已排序的子数组合并成一个有序数组
 
 时间复杂度：
 - 最好情况：O(n log n)
 - 最坏情况：O(n log n)
 - 平均情况：O(n log n)
 
 空间复杂度：O(n) — 需要额外的数组空间用于合并
 稳定性：稳定
 
 适用场景：
 - 需要稳定排序的场景
 - 链表排序（链表归并排序可做到 O(1) 空间）
 - 外部排序（数据量大到无法全部载入内存时）
 */
public enum MergeSort {
    
    /// 归并排序（返回新数组，不修改原数组）
    /// - Parameter nums: 待排序数组
    /// - Returns: 排序后的新数组
    public static func sort(_ nums: [Int]) -> [Int] {
        guard nums.count > 1 else { return nums }
        
        let mid = nums.count / 2
        let left = sort(Array(nums[0..<mid]))
        let right = sort(Array(nums[mid...]))
        
        return merge(left, right)
    }
    
    /// 归并排序（原地修改版本）
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sortInPlace(_ nums: inout [Int]) {
        guard nums.count > 1 else { return }
        mergeSortHelper(&nums, 0, nums.count - 1)
    }
    
    // MARK: - 私有辅助方法
    
    /// 合并两个有序数组
    private static func merge(_ left: [Int], _ right: [Int]) -> [Int] {
        var result: [Int] = []
        result.reserveCapacity(left.count + right.count)
        
        var i = 0, j = 0
        while i < left.count && j < right.count {
            if left[i] <= right[j] {
                result.append(left[i])
                i += 1
            } else {
                result.append(right[j])
                j += 1
            }
        }
        
        // 追加剩余元素
        while i < left.count {
            result.append(left[i])
            i += 1
        }
        while j < right.count {
            result.append(right[j])
            j += 1
        }
        
        return result
    }
    
    /// 递归辅助函数（原地版本）
    private static func mergeSortHelper(_ nums: inout [Int], _ left: Int, _ right: Int) {
        guard left < right else { return }
        
        let mid = left + (right - left) / 2
        mergeSortHelper(&nums, left, mid)
        mergeSortHelper(&nums, mid + 1, right)
        mergeInPlace(&nums, left, mid, right)
    }
    
    /// 原地合并 nums[left...mid] 和 nums[mid+1...right]
    private static func mergeInPlace(_ nums: inout [Int], _ left: Int, _ mid: Int, _ right: Int) {
        var temp = Array(nums[left...right])
        
        let leftEnd = mid - left
        let rightStart = mid + 1 - left
        let rightEnd = right - left
        
        var i = 0          // 左半部分指针
        var j = rightStart // 右半部分指针
        var k = left       // 原数组写入位置
        
        while i <= leftEnd && j <= rightEnd {
            if temp[i] <= temp[j] {
                nums[k] = temp[i]
                i += 1
            } else {
                nums[k] = temp[j]
                j += 1
            }
            k += 1
        }
        
        while i <= leftEnd {
            nums[k] = temp[i]
            i += 1
            k += 1
        }
        while j <= rightEnd {
            nums[k] = temp[j]
            j += 1
            k += 1
        }
    }
    
    // MARK: - 内置测试
    
    public enum Tests {
        public static func run() {
            // 纯函数版本
            let result1 = MergeSort.sort([5, 3, 8, 4, 2])
            assert(result1 == [2, 3, 4, 5, 8], "基本排序失败")
            
            let result2 = MergeSort.sort([])
            assert(result2 == [], "空数组排序失败")
            
            let result3 = MergeSort.sort([1])
            assert(result3 == [1], "单元素排序失败")
            
            // 原地版本
            var arr1 = [5, 4, 3, 2, 1]
            MergeSort.sortInPlace(&arr1)
            assert(arr1 == [1, 2, 3, 4, 5], "原地逆序排序失败")
            
            var arr2 = [3, 1, 4, 1, 5, 9, 2, 6]
            MergeSort.sortInPlace(&arr2)
            assert(arr2 == [1, 1, 2, 3, 4, 5, 6, 9], "原地含重复排序失败")
            
            print("✅ MergeSort 所有内置测试通过")
        }
    }
}
