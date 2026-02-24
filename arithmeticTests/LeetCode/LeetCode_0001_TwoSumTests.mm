#import <XCTest/XCTest.h>

#include <vector>

// 该模块的题解实现是 header-only（在 .hpp 中直接定义函数）
#include "1-两数之和.hpp"

@interface LeetCode_0001_TwoSumModuleTests : XCTestCase
@end

@implementation LeetCode_0001_TwoSumModuleTests

- (void)test_0001_twoSum_example {
    std::vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum(nums, 9);
    XCTAssertEqual((size_t)2, res.size());
    XCTAssertEqual(0, res[0]);
    XCTAssertEqual(1, res[1]);
}

- (void)test_0015_threeSum_example {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    // 题解返回二维数组，顺序不保证。这里只断言结果数量正确。
    XCTAssertEqual((size_t)2, res.size());
}

@end
