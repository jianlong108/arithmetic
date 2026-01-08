import Foundation

@_cdecl("run_remove_dup_ele_tests")
public func run_remove_dup_ele_tests() {
    FastSlowPointer.Tests.run()
}
/*
快慢指针技巧:
 1. 删除排序链表中的重复元素
 2. 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度
 3. 给你输入一个数组 nums，请你原地修改，将数组中的所有值为 0 的元素移到数组末

1. 初始化两个指针，慢指针 slow 和快指针 fast，均指向数组的起始位置。
2. 遍历数组，快指针 fast 从索引 1 开始向后移动。
3. 在每次迭代中，比较 nums[slow] 和 nums[fast] 的值：
   - 如果两者不相等，说明找到了一个新的唯一元素。将慢指针 slow 向前移动一位（slow += 1），并将 nums[fast] 的值赋给 nums[slow]。
   - 如果两者相等，说明遇到了重复元素，快指针 fast 继续向前移动，直到找到下一个不同的元素。
4. 重复步骤 3，直到快指针 fast 遍历完整个数组。
5. 最终，慢指针 slow 的位置加一（slow + 1）即为数组中唯一元素的个数，新数组的长度。
*/
// 输入一个有序的数组,你需要原地删除重复出现的元素,使得每个元素只出现一次,返回移除后数组的新长度.
public enum FastSlowPointer {
    public static func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard nums.count > 1 else {
            return nums.count
        }

        var slow = 0
        for fast in 1..<nums.count {
            if nums[slow] != nums[fast] {
                slow += 1
                nums[slow] = nums[fast]
            }
        }
        return slow + 1
    }

    // 原地移除数组中等于 val 的元素,返回新长度,不保证末尾元素顺序。
    public static func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var slow = 0
        for fast in 0..<nums.count {
            if nums[fast] != val {
                nums[slow] = nums[fast]
                slow += 1
            }
        }
        return slow
    }

    // 将所有 0 移到数组末尾,保持非零元素的相对顺序。
    public static func moveZeroes(_ nums: inout [Int]) {
        var p = removeElement(&nums, 0)
        while p < nums.count {
            nums[p] = 0
            p += 1
        }
    }

    // Lightweight unit tests for removing duplicates from sorted array.
    public enum Tests {
        public static func run() {
            var arr1 = [1, 1, 2]
            let len1 = FastSlowPointer.removeDuplicates(&arr1)
            print("removeDuplicates case1 ->", len1, Array(arr1[0..<len1]))
            assert(len1 == 2)
            assert(arr1[0..<len1] == [1, 2])

            var arr2 = [0,0,1,1,1,2,2,3,3,4]
            let len2 = FastSlowPointer.removeDuplicates(&arr2)
            print("removeDuplicates case2 ->", len2, Array(arr2[0..<len2]))
            assert(len2 == 5)
            assert(arr2[0..<len2] == [0,1,2,3,4])

            var arr3 = [3,2,2,3]
            let len3 = FastSlowPointer.removeElement(&arr3, 3)
            print("removeElement ->", len3, Array(arr3[0..<len3]))
            assert(len3 == 2)
            assert(Set(arr3[0..<len3]) == Set([2]))

            var arr4 = [0,1,0,3,12]
            FastSlowPointer.moveZeroes(&arr4)
            print("moveZeroes case1 ->", arr4)
            assert(arr4 == [1,3,12,0,0])

            var arr5 = [4,5]
            FastSlowPointer.moveZeroes(&arr5)
            print("moveZeroes case2 ->", arr5)
            assert(arr5 == [4,5])
        }
    }
}
