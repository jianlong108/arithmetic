import Foundation
// 差分数组的代码文件
@_cdecl("run_difference_array_tests")
public func run_difference_array_tests() {
    DifferenceArray.Tests.run()
}

// 差分数组: 输入一个整数数组,返回其差分数组.
// 应用算法题:
// 1. 区间增减操作,多次更新时效率更高.
public enum DifferenceArray {
    // 构建差分数组 diff，其中 diff[i] 表示 nums[i] - nums[i-1]，diff[0] = nums[0]。
    public static func buildDifference(_ nums: [Int]) -> [Int] {
        var diff = Array(repeating: 0, count: nums.count)
        diff[0] = nums[0]
        for i in 1..<nums.count {
            diff[i] = nums[i] - nums[i - 1]
        }
        return diff
    }

    // 在闭区间 [l, r] 上对原数组进行增量 update 的操作，假定 0 <= l <= r < nums.count。
    public static func rangeUpdate(_ diff: inout [Int], l: Int, r: Int, update: Int) {
        diff[l] += update
        if r + 1 < diff.count {
            diff[r + 1] -= update
        }
    }

    // 根据差分数组 diff 构建原数组 nums。
    public static func buildArrayFromDifference(_ diff: [Int]) -> [Int] {
        var nums = Array(repeating: 0, count: diff.count)
        nums[0] = diff[0]
        for i in 1..<diff.count {
            nums[i] = nums[i - 1] + diff[i]
        }
        return nums
    }

    // 1.输入一个长度为n数组A,初始情况下所有元素均为0.你将会被给出k个更新操作. 每个操作用一个三元组 [startIndex, endIndex, inc] 表示,
    // 你需要将子数组 A[startIndex ... endIndex] (包括 startIndex 和 endIndex ) 中的每个元素增加 inc.
    // 请你返回 k 次操作后的数组.
    public static func applyUpdates(n: Int, updates: [(startIndex: Int, endIndex: Int, inc: Int)]) -> [Int] {
        var diff = Array(repeating: 0, count: n)
        for update in updates {
            rangeUpdate(&diff, l: update.startIndex, r: update.endIndex, update: update.inc)
        }
        return buildArrayFromDifference(diff)
    }

    // 2. 有n个航班,从1到n进行编号.有一份航班预订表bookings,
    // 表中第i条预订记录bookings[i] = [firsti, lasti, seatsi]意味着在从firsti到lasti的每个航班上预订了seatsi个座位.
    // 请你返回一个长度为n的数组answer,其中answer[i]是航班i上预订的座位总数.
    public static func corpFlightBookings(_ bookings: [[Int]], _ n: Int) -> [Int] {
        var diff = Array(repeating: 0, count: n)
        for booking in bookings {
            let first = booking[0] - 1
            let last = booking[1] - 1
            let seats = booking[2]
            rangeUpdate(&diff, l: first, r: last, update: seats)
        }
        return buildArrayFromDifference(diff)
    }

    //3.你是一位开公交的司机,车上最初有capacity个空座位.你将会得到一份乘客行程表trips,
    // 其中trips[i] = [numPassengersi, fromi, toi]表示第i次行程有numPassengersi个乘客,
    // 他们需要从站点fromi上车,并在站点toi下车.请你判断是否能够在不超过座位容量capacity的情况下完成所有行程.
    public static func carPooling(_ trips: [[Int]], _ capacity: Int) -> Bool  {
        var diff = Array(repeating: 0, count: 1001)
        for trip in trips {
            let numPassengers = trip[0]
            let from = trip[1]
            let to = trip[2] - 1
            rangeUpdate(&diff, l: from, r: to, update: numPassengers)
        }
        var currentPassengers = 0
        for change in diff {
            currentPassengers += change
            if currentPassengers > capacity {
                return false
            }
        }
        return true
    }

    public enum Tests {
        public static func run() {
            testDifferenceBuild()
            testRangeUpdate()
        }

        private static func testDifferenceBuild() {
            let nums = [1, 3, 6, 10]
            let diff = buildDifference(nums)
            assert(diff == [1, 2, 3, 4], "DifferenceArray Test Failed")
        }

        private static func testRangeUpdate() {
            var nums = [1, 3, 6, 10]
            var diff = buildDifference(nums)
            rangeUpdate(&diff, l: 1, r: 2, update: 2)
            let updatedNums = buildArrayFromDifference(diff)
            assert(updatedNums == [1, 5, 8, 10], "DifferenceArray Range Update Test Failed")
        }
    }
}