import Foundation

@_cdecl("run_remove_dup_ele_tests")
public func run_remove_dup_ele_tests() {
    RemoveDupEle.Tests.run()
}

// 输入一个有序的数组,你需要原地删除重复出现的元素,使得每个元素只出现一次,返回移除后数组的新长度.
public enum RemoveDupEle {
    public static func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard nums.count > 1 else {
            return nums.count
        }

        var slow = 0
        for fast in 1..<nums.count {
            if nums[fast] != nums[slow] {
                slow += 1
                nums[slow] = nums[fast]
            }
        }
        return slow + 1
    }

    // Lightweight unit tests for removing duplicates from sorted array.
    public enum Tests {
        public static func run() {
            var arr1 = [1, 1, 2]
            let len1 = RemoveDupEle.removeDuplicates(&arr1)
            assert(len1 == 2)
            assert(arr1[0..<len1] == [1, 2])

            var arr2 = [0,0,1,1,1,2,2,3,3,4]
            let len2 = RemoveDupEle.removeDuplicates(&arr2)
            assert(len2 == 5)
            assert(arr2[0..<len2] == [0,1,2,3,4])
        }
    }
}