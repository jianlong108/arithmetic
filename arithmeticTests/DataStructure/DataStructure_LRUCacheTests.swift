//
//  DataStructure_LRUCacheTests.swift
//  arithmeticTests
//
//  Created by Claude Code
//  Copyright © 2026 wangjianlong. All rights reserved.
//

import XCTest

/// 测试 LRU (Least Recently Used) 最近最少使用缓存
///
/// LRU 缓存特性：
/// - O(1) 时间复杂度的 get 和 put 操作
/// - 使用哈希表和双向链表实现
/// - 淘汰最久未使用的元素
final class DataStructure_LRUCacheTests: XCTestCase {
    
    // MARK: - 基本操作测试
    
    func test_init_withValidCapacity() {
        let cache = LRUCache<Int, String>(capacity: 3)
        
        XCTAssertNil(cache.get(1), "新缓存应为空")
    }
    
    func test_put_singleElement() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        
        XCTAssertEqual(cache.get(1), "A", "应能获取刚插入的元素")
    }
    
    func test_put_multipleElements() {
        let cache = LRUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_put_updateExisting() {
        let cache = LRUCache<String, Int>(capacity: 2)
        cache.put("key", 100)
        cache.put("key", 200)
        
        XCTAssertEqual(cache.get("key"), 200, "更新后应返回新值")
    }
    
    func test_get_nonExistentKey() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        
        XCTAssertNil(cache.get(2), "不存在的键应返回 nil")
        XCTAssertNil(cache.get(100))
    }
    
    // MARK: - 容量限制测试
    
    func test_eviction_exceedsCapacity() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C") // 超出容量，应淘汰 1
        
        XCTAssertNil(cache.get(1), "最久未使用的 key 1 应被淘汰")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_eviction_afterAccess() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        cache.put(2, "B")
        _ = cache.get(1) // 访问 1，使其成为最近使用的
        cache.put(3, "C") // 应淘汰 2，而不是 1
        
        XCTAssertEqual(cache.get(1), "A", "最近访问的 1 应保留")
        XCTAssertNil(cache.get(2), "最久未使用的 2 应被淘汰")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_eviction_afterUpdate() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(1, "A_updated") // 更新 1，使其成为最近使用的
        cache.put(3, "C") // 应淘汰 2
        
        XCTAssertEqual(cache.get(1), "A_updated")
        XCTAssertNil(cache.get(2), "最久未使用的 2 应被淘汰")
        XCTAssertEqual(cache.get(3), "C")
    }
    
    func test_capacity_one() {
        let cache = LRUCache<Int, String>(capacity: 1)
        cache.put(1, "A")
        cache.put(2, "B") // 应淘汰 1
        
        XCTAssertNil(cache.get(1))
        XCTAssertEqual(cache.get(2), "B")
    }
    
    func test_capacity_zero() {
        let cache = LRUCache<Int, String>(capacity: 0)
        cache.put(1, "A")
        
        XCTAssertNil(cache.get(1), "容量为 0 时不应存储任何元素")
    }
    
    // MARK: - LRU 顺序测试
    
    func test_lruOrder_sequentialAccess() {
        let cache = LRUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        _ = cache.get(1) // 访问 1
        cache.put(4, "D") // 应淘汰 2（最久未使用）
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertNil(cache.get(2))
        XCTAssertEqual(cache.get(3), "C")
        XCTAssertEqual(cache.get(4), "D")
    }
    
    func test_lruOrder_multipleAccesses() {
        let cache = LRUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        _ = cache.get(1)
        _ = cache.get(2)
        _ = cache.get(1)
        cache.put(4, "D") // 应淘汰 3（最久未使用）
        
        XCTAssertEqual(cache.get(1), "A")
        XCTAssertEqual(cache.get(2), "B")
        XCTAssertNil(cache.get(3), "3 应被淘汰")
        XCTAssertEqual(cache.get(4), "D")
    }
    
    func test_lruOrder_complexScenario() {
        let cache = LRUCache<Int, String>(capacity: 3)
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        _ = cache.get(1)     // 访问顺序: 1 最新
        cache.put(4, "D")     // 淘汰 2, 顺序: 4, 1, 3
        _ = cache.get(3)     // 访问顺序: 3, 4, 1
        cache.put(5, "E")     // 淘汰 1, 顺序: 5, 3, 4
        
        XCTAssertNil(cache.get(1))
        XCTAssertNil(cache.get(2))
        XCTAssertEqual(cache.get(3), "C")
        XCTAssertEqual(cache.get(4), "D")
        XCTAssertEqual(cache.get(5), "E")
    }
    
    // MARK: - 边界情况测试
    
    func test_multiplePuts_sameKey() {
        let cache = LRUCache<String, Int>(capacity: 2)
        cache.put("key", 1)
        cache.put("key", 2)
        cache.put("key", 3)
        
        XCTAssertEqual(cache.get("key"), 3, "多次 put 同一键应保留最新值")
    }
    
    func test_alternatingPutGet() {
        let cache = LRUCache<Int, String>(capacity: 2)
        cache.put(1, "A")
        XCTAssertEqual(cache.get(1), "A")
        cache.put(2, "B")
        XCTAssertEqual(cache.get(2), "B")
        cache.put(3, "C")
        XCTAssertNil(cache.get(1))
        XCTAssertEqual(cache.get(2), "B")
    }
    
    func test_fillAndEmpty() {
        let cache = LRUCache<Int, String>(capacity: 3)
        
        // 填满
        cache.put(1, "A")
        cache.put(2, "B")
        cache.put(3, "C")
        
        // 全部淘汰
        cache.put(4, "D")
        cache.put(5, "E")
        cache.put(6, "F")
        
        // 原有元素应全部不存在
        XCTAssertNil(cache.get(1))
        XCTAssertNil(cache.get(2))
        XCTAssertNil(cache.get(3))
        
        // 新元素应存在
        XCTAssertEqual(cache.get(4), "D")
        XCTAssertEqual(cache.get(5), "E")
        XCTAssertEqual(cache.get(6), "F")
    }
    
    // MARK: - 不同数据类型测试
    
    func test_stringKeys() {
        let cache = LRUCache<String, Int>(capacity: 2)
        cache.put("foo", 1)
        cache.put("bar", 2)
        
        XCTAssertEqual(cache.get("foo"), 1)
        XCTAssertEqual(cache.get("bar"), 2)
    }
    
    func test_complexValues() {
        struct User {
            let id: Int
            let name: String
        }
        
        let cache = LRUCache<Int, User>(capacity: 2)
        cache.put(1, User(id: 1, name: "Alice"))
        cache.put(2, User(id: 2, name: "Bob"))
        
        XCTAssertEqual(cache.get(1)?.name, "Alice")
        XCTAssertEqual(cache.get(2)?.id, 2)
    }
    
    // MARK: - 性能测试
    
    func test_performance_largeCapacity() {
        let cache = LRUCache<Int, String>(capacity: 1000)
        
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
