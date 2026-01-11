//
//  LeftRightPointer.swift
//  arithmetic
//
//  Created by JL on 2026/1/7.
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import Foundation

@_cdecl("run_left_right_pointer_tests")
public func run_left_right_pointer_tests() {
	LeftRightPointer.Tests.run()
}

/*
 左右指针的常⽤算法
 1. 输⼊一个已按升序排列的有序数组 nums 和一个目标值 target，在 nums 中找到两
	个数使得它们相加之和等于 target，返回这两个数的索引（1-based）。

 2. 输⼊一个已按升序排列的有序数组 nums 和一个目标值 target，在 nums 中找到三
	个数使得它们相加之和等于 target，返回所有满足条件的三元组索引（1-based）。

 3. 反转一个 char[] 类型的字符数组。

 4. 判断一个字符串是不是回文串。
 5. 给你输入一个字符串，返回这个字符串中的最长回文子串。
*/

public enum LeftRightPointer {
	// 1. Two-sum on sorted array, return 1-based indices.
	public static func twoSumSorted(_ nums: [Int], target: Int) -> (Int, Int)? {
		var left = 0
		var right = nums.count - 1
		while left < right {
			let sum = nums[left] + nums[right]
			if sum == target {
				return (left + 1, right + 1)
			} else if sum < target {
				left += 1
			} else {
				right -= 1
			}
		}
		return nil
	}

	// 2. Three-sum on sorted array, return all unique triplets of 1-based indices.
	public static func threeSumSorted(_ nums: [Int], target: Int) -> [(Int, Int, Int)] {
		guard nums.count >= 3 else { return [] }
		var result: [(Int, Int, Int)] = []
		for i in 0..<(nums.count - 2) {
			if i > 0 && nums[i] == nums[i - 1] { continue }
			var left = i + 1
			var right = nums.count - 1
			while left < right {
				let sum = nums[i] + nums[left] + nums[right]
				if sum == target {
					result.append((i + 1, left + 1, right + 1))
					let leftVal = nums[left]
					let rightVal = nums[right]
					repeat { left += 1 } while left < right && nums[left] == leftVal
					repeat { right -= 1 } while left < right && nums[right] == rightVal
				} else if sum < target {
					left += 1
				} else {
					right -= 1
				}
			}
		}
		return result
	}

	// 3. Reverse a character array in-place.
	public static func reverseChars(_ chars: inout [Character]) {
		var left = 0
		var right = chars.count - 1
		while left < right {
			chars.swapAt(left, right)
			left += 1
			right -= 1
		}
	}

    // 判断一个字符串是不是回文串。
	// 4. Check if a string is a palindrome (two-pointer from ends).
	public static func isPalindrome(_ s: String) -> Bool {
		let chars = Array(s)
		var left = 0
		var right = chars.count - 1
		while left < right {
			if chars[left] != chars[right] {
				return false
			}
			left += 1
			right -= 1
		}
		return true
	}

	// 5. Longest palindromic substring via expand-around-center.
	public static func longestPalindrome(_ s: String) -> String {
		let chars = Array(s)
		let n = chars.count
		if n < 2 { return s }

        // 如果 leftStart 和 rightStart 相等,则是奇数回文;如果不等,则是偶数回文.
        // 求出以 leftStart 和 rightStart 为中心的最长回文子串的起止索引.
		func expand(_ leftStart: Int, _ rightStart: Int) -> (Int, Int) {
			var l = leftStart
			var r = rightStart
			while l >= 0 && r < n && chars[l] == chars[r] {
				l -= 1
				r += 1
			}
			return (l + 1, r - 1) // inclusive bounds
		}

		var best = (start: 0, end: 0)
		for i in 0..<n {
			let odd = expand(i, i)
			if odd.1 - odd.0 > best.end - best.start { 
                best = (odd.0, odd.1) 
            }

			let even = expand(i, i + 1)
			if even.1 - even.0 > best.end - best.start { 
                best = (even.0, even.1) 
            }
		}

		return String(chars[best.start...best.end])
	}

	// MARK: - Tests
	public enum Tests {
		public static func run() {
			testTwoSum()
			testThreeSum()
			testReverseChars()
			testIsPalindrome()
			testLongestPalindrome()
		}

		private static func testTwoSum() {
			let nums = [2, 7, 11, 15]
			let res = twoSumSorted(nums, target: 9)
			print("twoSumSorted ->", res as Any)
			assert(res?.0 == 1 && res?.1 == 2)
		}

		private static func testThreeSum() {
			let nums = [-4, -1, -1, 0, 1, 2]
			let res = threeSumSorted(nums, target: 0)
			print("threeSumSorted ->", res)
			// Expected unique triplets indices for sums to zero: (-1,-1,2) and (-1,0,1)
			assert(res.count == 2)
		}

		private static func testReverseChars() {
			var chars: [Character] = ["h", "e", "l", "l", "o"]
			reverseChars(&chars)
			print("reverseChars ->", String(chars))
			assert(String(chars) == "olleh")
		}

		private static func testIsPalindrome() {
			print("isPalindrome ->", isPalindrome("abba"), isPalindrome("abc"))
			assert(isPalindrome("abba") == true)
			assert(isPalindrome("abc") == false)
		}

		private static func testLongestPalindrome() {
			let s1 = "babad"
			let s2 = "cbbd"
			let r1 = longestPalindrome(s1)
			let r2 = longestPalindrome(s2)
			print("longestPalindrome ->", r1, r2)
			assert(r1 == "bab" || r1 == "aba")
			assert(r2 == "bb")
		}
	}
}
