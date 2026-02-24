//
//  HeapSort.swift
//  arithmetic
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_heap_sort_tests")
public func run_heap_sort_tests() {
    HeapSort.Tests.run()
}

/*
 堆排序 (Heap Sort)
 
 基本思想：
 利用堆（完全二叉树）这种数据结构来排序。
 1. 建堆（Build Max Heap）：将数组构建成最大堆
    - 从最后一个非叶子节点开始，自底向上执行下沉（sift down）操作
 2. 排序：反复将堆顶（最大值）与末尾元素交换，然后缩小堆的范围并重新调整堆
 
 堆的性质（最大堆）：
 - 父节点 >= 子节点
 - 对于下标 i 的节点：
   - 左子节点下标 = 2*i + 1
   - 右子节点下标 = 2*i + 2
   - 父节点下标 = (i - 1) / 2
 
 时间复杂度：
 - 最好情况：O(n log n)
 - 最坏情况：O(n log n)
 - 平均情况：O(n log n)
 
 空间复杂度：O(1) — 原地排序
 稳定性：不稳定
 
 适用场景：
 - 需要 O(n log n) 最坏时间保证的场景
 - Top K 问题（取最大/最小的 K 个元素）
 - 优先队列
 */
public enum HeapSort {
    
    /// 堆排序
    /// - Parameter nums: 待排序数组（原地修改）
    public static func sort(_ nums: inout [Int]) {
        let n = nums.count
        guard n > 1 else { return }
        
        // 第一步：建最大堆（从最后一个非叶子节点开始）
        for i in stride(from: n / 2 - 1, through: 0, by: -1) {
            siftDown(&nums, i, n)
        }
        
        // 第二步：逐步将堆顶（最大值）移到数组末尾
        for end in stride(from: n - 1, through: 1, by: -1) {
            // 将堆顶（当前最大值）与末尾元素交换
            nums.swapAt(0, end)
            // 缩小堆的范围，对新堆顶执行下沉
            siftDown(&nums, 0, end)
        }
    }
    
    // MARK: - 私有辅助方法
    
    /// 下沉操作：确保以 index 为根的子树满足最大堆性质
    /// - Parameters:
    ///   - nums: 数组
    ///   - index: 要下沉的节点索引
    ///   - heapSize: 当前堆的大小
    private static func siftDown(_ nums: inout [Int], _ index: Int, _ heapSize: Int) {
        var parent = index
        
        while true {
            let leftChild = 2 * parent + 1
            let rightChild = 2 * parent + 2
            var largest = parent
            
            // 找到父节点、左子节点、右子节点中的最大值
            if leftChild < heapSize && nums[leftChild] > nums[largest] {
                largest = leftChild
            }
            if rightChild < heapSize && nums[rightChild] > nums[largest] {
                largest = rightChild
            }
            
            // 如果最大值就是父节点，则堆性质已满足
            if largest == parent { break }
            
            // 否则交换并继续下沉
            nums.swapAt(parent, largest)
            parent = largest
        }
    }
    
    // MARK: - 内置测试
    
    public enum Tests {
        public static func run() {
            var arr1 = [5, 3, 8, 4, 2]
            HeapSort.sort(&arr1)
            assert(arr1 == [2, 3, 4, 5, 8], "基本排序失败")
            
            var arr2: [Int] = []
            HeapSort.sort(&arr2)
            assert(arr2 == [], "空数组排序失败")
            
            var arr3 = [1]
            HeapSort.sort(&arr3)
            assert(arr3 == [1], "单元素排序失败")
            
            var arr4 = [5, 4, 3, 2, 1]
            HeapSort.sort(&arr4)
            assert(arr4 == [1, 2, 3, 4, 5], "逆序排序失败")
            
            var arr5 = [3, 1, 4, 1, 5, 9, 2, 6]
            HeapSort.sort(&arr5)
            assert(arr5 == [1, 1, 2, 3, 4, 5, 6, 9], "含重复元素排序失败")
            
            print("✅ HeapSort 所有内置测试通过")
        }
    }
}
