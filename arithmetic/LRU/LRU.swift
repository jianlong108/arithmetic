import Foundation

// 这是 LRU (Least Recently Used) 最近最少使用缓存的代码文件
@_cdecl("run_lru_tests")
public func run_lru_tests() {
    LRU.Tests.run()
}

// LRU (Least Recently Used) 最近最少使用缓存
// 使用哈希表和双向链表实现，支持 O(1) 时间复杂度的 get 和 put 操作。
//


/// 双向链表节点
fileprivate class Node<Key: Hashable, Value> {
    var key: Key
    var value: Value
    var prev: Node?
    var next: Node?

    init(key: Key, value: Value) {
        self.key = key
        self.value = value
    }
}

/// 双向链表
fileprivate class DoublyLinkedList<Key: Hashable, Value> {
    private var head: Node<Key, Value>?
    private var tail: Node<Key, Value>?

    init() {}

    /// 将节点添加到链表头部
    func add_to_head(_ node: Node<Key, Value>) {
        node.next = head
        head?.prev = node
        head = node
        if tail == nil {
            tail = node
        }
    }

    /// 从链表中移除一个节点
    func remove(_ node: Node<Key, Value>) {
        if node.prev != nil {
            node.prev?.next = node.next
        } else {
            head = node.next
        }

        if node.next != nil {
            node.next?.prev = node.prev
        } else {
            tail = node.prev
        }
    }

    /// 移除并返回尾部节点（最久未使用的）
    func remove_tail() -> Node<Key, Value>? {
        guard let tail = self.tail else {
            return nil
        }
        remove(tail)
        return tail
    }
}

/// LRU 缓存实现
public class LRUCache<Key: Hashable, Value> {
    private let capacity: Int
    private var cache: [Key: Node<Key, Value>] = [:]
    private let list = DoublyLinkedList<Key, Value>()

    public init(capacity: Int) {
        self.capacity = max(0, capacity)
    }

    /// 获取缓存中的值
    /// 如果键存在，则将其移动到链表头部并返回值
    public func get(_ key: Key) -> Value? {
        guard let node = cache[key] else {
            return nil
        }
        // 将访问的节点移动到头部
        list.remove(node)
        list.add_to_head(node)
        return node.value
    }

    /// 插入或更新缓存中的值
    /// 如果键已存在，则更新其值并移动到头部
    /// 如果是新键，则插入到头部
    /// 如果超出容量，则移除最久未使用的条目
    public func put(_ key: Key, _ value: Value) {
        if capacity == 0 { return }

        if let node = cache[key] {
            // 键已存在，更新值并移动到头部
            node.value = value
            list.remove(node)
            list.add_to_head(node)
        } else {
            // 键不存在，创建新节点
            let newNode = Node(key: key, value: value)
            cache[key] = newNode
            list.add_to_head(newNode)

            // 如果超出容量，移除最末尾的节点
            if cache.count > capacity {
                if let tail = list.remove_tail() {
                    cache.removeValue(forKey: tail.key)
                }
            }
        }
    }
    
    /// 打印缓存内容以供调试
    public func printCache() {
        var description = "LRUCache: ["
        var currentNode = list.head
        while let node = currentNode {
            description += "\(node.key): \(node.value)"
            if node.next != nil {
                description += ", "
            }
            currentNode = node.next
        }
        description += "]"
        print(description)
    }
}

// MARK: - Tests
public enum LRUCacheTests {
    public static func run() {
        print("Running LRUCache tests...")
        let cache = LRUCache<Int, String>(capacity: 3)

        cache.put(1, "A")
        cache.printCache() // [1: A]

        cache.put(2, "B")
        cache.printCache() // [2: B, 1: A]

        cache.put(3, "C")
        cache.printCache() // [3: C, 2: B, 1: A]

        // 访问 1，使其变为最近使用的
        _ = cache.get(1)
        cache.printCache() // [1: A, 3: C, 2: B]

        // 添加 4，容量已满，最久未使用的 2 将被移除
        cache.put(4, "D")
        cache.printCache() // [4: D, 1: A, 3: C]

        // 访问 3
        _ = cache.get(3)
        cache.printCache() // [3: C, 4: D, 1: A]
        
        // 添加 5, 1 将被移除
        cache.put(5, "E")
        cache.printCache() // [5: E, 3: C, 4: D]
        
        // 尝试获取被移除的 2
        let value2 = cache.get(2)
        print("Value for key 2: \(value2 ?? "nil")") // nil
        
        print("LRUCache tests finished.")
    }
}

// MARK: - LFU Cache Implementation

// LFU (Least Frequently Used) 最少使用频率缓存
// 淘汰访问频率最低的元素，如果频率相同则淘汰最早访问的元素
@_cdecl("run_lfu_tests")
public func run_lfu_tests() {
    LFU.Tests.run()
}

/// LFU 缓存节点
fileprivate class LFUNode<Key: Hashable, Value> {
    var key: Key
    var value: Value
    var freq: Int  // 访问频率
    var prev: LFUNode?
    var next: LFUNode?
    
    init(key: Key, value: Value, freq: Int = 1) {
        self.key = key
        self.value = value
        self.freq = freq
    }
}

/// 频率桶 - 维护相同频率的节点
fileprivate class FrequencyList<Key: Hashable, Value> {
    var head: LFUNode<Key, Value>?
    var tail: LFUNode<Key, Value>?
    var size: Int = 0
    
    init() {}
    
    /// 添加节点到链表头部
    func addToHead(_ node: LFUNode<Key, Value>) {
        node.next = head
        node.prev = nil
        head?.prev = node
        head = node
        if tail == nil {
            tail = node
        }
        size += 1
    }
    
    /// 从链表中移除节点
    func remove(_ node: LFUNode<Key, Value>) {
        if node === head {
            head = node.next
        }
        if node === tail {
            tail = node.prev
        }
        node.prev?.next = node.next
        node.next?.prev = node.prev
        node.prev = nil
        node.next = nil
        size -= 1
    }
    
    /// 移除并返回尾部节点（最早访问的）
    func removeTail() -> LFUNode<Key, Value>? {
        guard let tail = self.tail else { return nil }
        remove(tail)
        return tail
    }
    
    var isEmpty: Bool {
        return size == 0
    }
}

/// LFU 缓存实现
public class LFUCache<Key: Hashable, Value> {
    private let capacity: Int
    private var cache: [Key: LFUNode<Key, Value>] = [:]  // key -> node
    private var freqMap: [Int: FrequencyList<Key, Value>] = [:]  // frequency -> list
    private var minFreq: Int = 0  // 当前最小频率
    
    public init(capacity: Int) {
        self.capacity = max(0, capacity)
    }
    
    /// 获取缓存中的值
    /// 如果键存在，增加其访问频率并返回值
    public func get(_ key: Key) -> Value? {
        guard let node = cache[key] else {
            return nil
        }
        // 更新节点频率
        updateFrequency(node)
        return node.value
    }
    
    /// 插入或更新缓存中的值
    public func put(_ key: Key, _ value: Value) {
        if capacity == 0 { return }
        
        if let node = cache[key] {
            // 键已存在，更新值和频率
            node.value = value
            updateFrequency(node)
        } else {
            // 键不存在，检查容量
            if cache.count >= capacity {
                // 移除最低频率的最早访问节点
                evict()
            }
            
            // 创建新节点，初始频率为 1
            let newNode = LFUNode(key: key, value: value, freq: 1)
            cache[key] = newNode
            
            // 添加到频率为 1 的链表
            if freqMap[1] == nil {
                freqMap[1] = FrequencyList()
            }
            freqMap[1]?.addToHead(newNode)
            minFreq = 1
        }
    }
    
    /// 更新节点的访问频率
    private func updateFrequency(_ node: LFUNode<Key, Value>) {
        let oldFreq = node.freq
        let newFreq = oldFreq + 1
        
        // 从旧频率链表中移除
        freqMap[oldFreq]?.remove(node)
        
        // 如果旧频率链表为空且是最小频率，更新最小频率
        if freqMap[oldFreq]?.isEmpty == true {
            freqMap.removeValue(forKey: oldFreq)
            if minFreq == oldFreq {
                minFreq = newFreq
            }
        }
        
        // 更新节点频率
        node.freq = newFreq
        
        // 添加到新频率链表
        if freqMap[newFreq] == nil {
            freqMap[newFreq] = FrequencyList()
        }
        freqMap[newFreq]?.addToHead(node)
    }
    
    /// 淘汰最低频率的最早访问节点
    private func evict() {
        guard let list = freqMap[minFreq],
              let tail = list.removeTail() else {
            return
        }
        
        cache.removeValue(forKey: tail.key)
        
        // 如果链表为空，移除该频率
        if list.isEmpty {
            freqMap.removeValue(forKey: minFreq)
        }
    }
    
    /// 打印缓存内容以供调试
    public func printCache() {
        var description = "LFUCache: ["
        var items: [(Key, Value, Int)] = []
        
        // 按频率从高到低排序
        let sortedFreqs = freqMap.keys.sorted(by: >)
        for freq in sortedFreqs {
            if let list = freqMap[freq] {
                var node = list.head
                while let current = node {
                    items.append((current.key, current.value, current.freq))
                    node = current.next
                }
            }
        }
        
        for (index, item) in items.enumerated() {
            description += "\(item.0): \(item.1) (freq: \(item.2))"
            if index < items.count - 1 {
                description += ", "
            }
        }
        description += "]"
        print(description)
    }
}

// MARK: - LFU Tests
public enum LFU {
    public enum Tests {
        public static func run() {
            print("\n=== Running LFU Cache tests ===")
            let cache = LFUCache<Int, String>(capacity: 3)
            
            // 添加三个元素
            cache.put(1, "A")
            cache.printCache() // [1: A (freq: 1)]
            
            cache.put(2, "B")
            cache.printCache() // [2: B (freq: 1), 1: A (freq: 1)]
            
            cache.put(3, "C")
            cache.printCache() // [3: C (freq: 1), 2: B (freq: 1), 1: A (freq: 1)]
            
            // 访问 1 两次，频率变为 3
            _ = cache.get(1)
            _ = cache.get(1)
            cache.printCache() // [1: A (freq: 3), 3: C (freq: 1), 2: B (freq: 1)]
            
            // 访问 2 一次，频率变为 2
            _ = cache.get(2)
            cache.printCache() // [1: A (freq: 3), 2: B (freq: 2), 3: C (freq: 1)]
            
            // 添加 4，容量已满，淘汰频率最低的 3
            cache.put(4, "D")
            cache.printCache() // [1: A (freq: 3), 2: B (freq: 2), 4: D (freq: 1)]
            
            // 尝试获取被淘汰的 3
            let value3 = cache.get(3)
            print("Value for key 3: \(value3 ?? "nil")") // nil
            
            // 访问 4，频率变为 2
            _ = cache.get(4)
            cache.printCache() // [1: A (freq: 3), 2: B (freq: 2), 4: D (freq: 2)]
            
            // 添加 5，淘汰频率最低且最早的（2 或 4，选最早的 2）
            cache.put(5, "E")
            cache.printCache() // [1: A (freq: 3), 4: D (freq: 2), 5: E (freq: 1)]
            
            // 更新已存在的键
            cache.put(1, "A_updated")
            cache.printCache() // [1: A_updated (freq: 4), 4: D (freq: 2), 5: E (freq: 1)]
            
            print("LFU Cache tests finished.\n")
        }
    }
}

// MARK: - LRU enum wrapper
public enum LRU {
    public enum Tests {
        public static func run() {
            print("\n=== Running LRU Cache tests ===")
            LRUCacheTests.run()
            print()
        }
    }
}
