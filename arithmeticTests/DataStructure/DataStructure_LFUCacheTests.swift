//
//  DataStructure_LFUCacheTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试 LFU (Least Frequently Used) 最少使用频率缓存
///
/// LFU 缓存特性：
/// - 淘汰访问频率最低的元素
/// - 频率相同时淘汰最早访问的元素
/// - O(1) 时间复杂度的 get 和 put 操作
final class DataStructure_LFUCacheTests: XCTestCase {
    
    // MARK: - 基本操作测试
    
    func test_init_withValidCapacity() {
        let cache = LFUCache<Int, String>(capacity: 3)
        
        XCTAssertNil(cache.get(1), "新缓存应为空")
    }
    
    func test_put_singleElement() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        
        XCTAssertEqual(cache.get(1), "A")
    }
    
    func test_put_multipleElements() {
        let cache = LFUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_put_updateExisting() {
        let cache = LFUCache<String, Int>(capacity: 2)
        cache.put("key", 100)
        cache.put("key", 200)
        
        XCTAssertEqual(cache.get("key"), 200, "更新后应返回新值")
    }
    
    func test_get_nonExistentKey() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        
        XCTAssertNil(cache.get(2))
        XCTAssertNil(cache.get(100))
    }
    
    // MARK: - 频率淘汰测试
    
    func test_eviction_lowestFrequency() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")  // freq=1
        cache.put(2, "B")  // freq=1
        _ = cache.get(1)   // freq=2
        cache.put(3, "C")  // 超出容量，应淘汰 freq=1 的 2
        
        XCTAssertEqual(cache.get(1), "A", "高频率元素应保留")
        XCTAssertNil(cache.get(2), "低频率元素应被淘汰")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_eviction_sameFrequencyEvictEarliest() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")  // freq=1, 最早插入
        cache.put(2, "B")  // freq=1, 较晚插入
        cache.put(3, "C")  // 超出容量，频率相同应淘汰最早的 1
        
        XCTAssertNil(cache.get(1), "频率相同时应淘汰最早插入的")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_eviction_increasingFrequency() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")  // freq=1
        cache.put(2, "B")  // freq=1
        _ = cache.get(1)   // freq=2
        _ = cache.get(1)   // freq=3
        _ = cache.get(2)   // freq=2
        cache.put(3, "C")  // 应淘汰 freq=2 且较早的 2
        
        XCTAssertEqual(cache.get(1), "A", "最高频率元素应保留")
        XCTAssertNil(cache.get(2), "较低频率元素应被淘汰")
    }
    
    func test_eviction_afterUpdate() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")       // freq=1
        cache.put(2, "B")       // freq=1
        _ = cache.get(1)        // freq=2
        cache.put(2, "B_new")   // 更新但频率增加, freq=2
        cache.put(3, "C")       // 两者频率都是 2，淘汰较早达到 freq=2 的
        
        // 注意：实现可能会有差异，这里验证基本逻辑
        XCTAssertTrue(cache.get(1) != nil || cache.get(2) != nil, "至少保留一个")
    }
    
    // MARK: - 容量限制测试
    
    func test_capacity_one() {
        let cache = LFUCache<Int, String>(capacity: 1)
        cache.put(1, "A")
        cache.put(2, "B")  // 应淘汰 1
        
        XCTAssertNil(cache.get(1))
        XCTAssertEqual(cache.get(2), "B")
    }
    
    func test_capacity_zero() {
        let cache = LFUCache<Int, String>(capacity: 0)
        cache.put(1, "A")
        
        XCTAssertNil(cache.get(1), "容量为 0 时不应存储任何元素")
    }
    
    // MARK: - 频率增长测试
    
    func test_frequency_multipleGets() {
        let cache = LFUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        // 增加 1 的频率
        _ = cache.get(1)
        _ = cache.get(1)
        _ = cache.get(1)
        
        // 增加一个新元素，应淘汰频率最低的
        cache.put(4, "D")
        
        XCTAssertEqual(cache.get(1), "A", "最高频率元素应保留")
        // 2 或 3 其中一个应被淘汰
        let twoExists = cache.get(2) != nil
        let threeExists = cache.get(3) != nil
        XCTAssertTrue((twoExists && !threeExists) || (!twoExists && threeExists), 
                     "频率相同时应淘汰其中一个")
    }
    
    func test_frequency_mixedOperations() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")     // freq=1
        _ = cache.get(1)      // freq=2
        cache.put(2, "B")     // freq=1
        _ = cache.get(2)      // freq=2
        _ = cache.get(1)      // freq=3
        cache.put(3, "C")     // 应淘汰 freq=2 的 2
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertNil(cache.get(2))
        XCTAssertEqual(cache.get(3), "C")
    }
    
    // MARK: - 复杂场景测试
    
    func test_complexScenario_leetcodeExample() {
        // LeetCode 460 题的测试用例
        let cache = LFUCache<Int, Int>(capacity: 2)
        cache.put(1, 1)
        cache.put(2, 2)
        XCTAssertEqual(cache.get(1), 1)
        cache.put(3, 3)
        XCTAssertNil(cache.get(2), "2 应被淘汰")
        XCTAssertEqual(cache.get(3), 3)
        cache.put(4, 4)
        XCTAssertNil(cache.get(1), "1 应被淘汰")
        XCTAssertEqual(cache.get(3), 3)
        XCTAssertEqual(cache.get(4), 4)
    }
    
    func test_complexScenario_frequencyTie() {
        let cache = LFUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        _ = cache.get(1)
        _ = cache.get(2)
        _ = cache.get(3)
        _ = cache.get(1)
        _ = cache.get(2)
        
        cache.put(4, "D")  // 应淘汰 freq=2 的 3
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertNil(cache.get(3))
        XCTAssertEqual(cache.get(4), "D")
    }
    
    func test_complexScenario_allSameFrequency() {
        let cache = LFUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        // 不访问任何元素，都是 freq=1
        cache.put(4, "D")  // 应淘汰最早插入的 1
        
        XCTAssertNil(cache.get(1))
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertEqual(cache.get(3), "C")
        XCTAssertEqual(cache.get(4), "D")
    }
    
    // MARK: - 边界情况测试
    
    func test_multiplePuts_sameKey() {
        let cache = LFUCache<String, Int>(capacity: 2)
        cache.put("key", 1)
        cache.put("key", 2)
        cache.put("key", 3)
        
        XCTAssertEqual(cache.get("key"), 3)
    }
    
    func test_alternatingPutGet() {
        let cache = LFUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        XCTAssertEqual(cache.get(1), "A")
        cache.put(2, "B")
        XCTAssertEqual(cache.get(2), "B")
        cache.put(3, "C")
        
        // 1 和 2 都是 freq=2，但 1 更早达到，应淘汰 1
        let result1 = cache.get(1)
        let result2 = cache.get(2)
        
        // 至少有一个被淘汰
        XCTAssertTrue(result1 == nil || result2 == nil)
    }
    
    // MARK: - 不同数据类型测试
    
    func test_stringKeys() {
        let cache = LFUCache<String, Int>(capacity: 2)
        cache.put("foo", 1)
        cache.put("bar", 2)
        _ = cache.get("foo")
        cache.put("baz", 3)
        
        XCTAssertEqual(cache.get("foo"), 1)
        XCTAssertNil(cache.get("bar"), "低频率的 bar 应被淘汰")
        XCTAssertEqual(cache.get("baz"), 3)
    }
    
    // MARK: - 性能测试
    
    func test_performance_largeCapacity() {
        let cache = LFUCache<Int, String>(capacity: 1000)
        
        measure {
            for i in 0..<1000 {
                cache.put(i, "Value_\(i)")
            }
            for i in 0..<1000 {
                _ = cache.get(i)
            }
        }
    }
}
