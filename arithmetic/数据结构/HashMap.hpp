//
//  HashMap.hpp
//  算法 - 哈希表(Hash Map) / 拉链法(Separate Chaining)
//
//  设计与原理说明
//  ----------------
//  1) HashMap 的核心思想
//     - 把 key 通过哈希函数 hash(key) 映射成一个整数，再对桶数组长度取模：index = hash(key) % bucketCount。
//     - 每个 index 对应一个“桶”(bucket)。桶里存放若干键值对。
//     - 理想情况下，不同 key 会均匀分布到不同桶里，从而实现平均 O(1) 的插入/查找/删除。
//
//  2) 为什么会有冲突？
//     - 不同 key 可能计算出相同的 index（哈希冲突）。
//     - 冲突不是 bug，而是哈希表必须处理的情况。
//
//  3) 为什么选择“拉链法”解决冲突？
//     - 拉链法：每个桶里是一条链表（这里用单链表）。冲突的元素都挂在同一个桶的链表上。
//     - 优点：
//         * 删除操作很自然（找到节点后从链表中摘除即可），不需要开放寻址那种“墓碑标记”。
//         * 装载因子(load factor)允许更高，冲突时只影响该桶的链表，不会像线性探测那样产生“聚集”。
//         * 实现直观，便于学习数据结构。
//     - 代价：
//         * 每个节点需要额外的 next 指针，存在一定内存开销。
//
//  4) 为什么要扩容/rehash？
//     - 当元素越来越多，如果桶数量不变，链表会变长，操作会退化到 O(n)。
//     - 因此设置最大装载因子（默认 0.75）：size / bucketCount > maxLoadFactor 时触发扩容。
//     - 扩容后桶数量增大，并对所有元素重新计算 index（rehash），以恢复均匀分布。
//
//  说明：本实现面向“学习+可用”场景，接口尽量贴近常见 map：put/get/remove/contains/operator[]。
//
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <sstream>
#include <utility>
#include <stdexcept>

using namespace std;

template <class K,
          class V,
          class Hash = std::hash<K>,
          class KeyEqual = std::equal_to<K>>
class HashMap {
private:
    struct Node {
        K key;
        V value;
        Node *next;

        Node(const K &k, const V &v, Node *n) : key(k), value(v), next(n) {}
        Node(K &&k, V &&v, Node *n) : key(std::move(k)), value(std::move(v)), next(n) {}
    };

    vector<Node *> m_buckets;
    size_t m_size;
    float m_maxLoadFactor;
    Hash m_hasher;
    KeyEqual m_keyEqual;

private:
    size_t bucketIndexForKey(const K &key, size_t bucketCount) const {
        // bucketCount 必须 > 0
        return static_cast<size_t>(m_hasher(key)) % bucketCount;
    }

    Node *findNode(const K &key, size_t index) const {
        Node *cur = m_buckets[index];
        while (cur) {
            if (m_keyEqual(cur->key, key)) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

    void rehash(size_t newBucketCount) {
        if (newBucketCount < 1) newBucketCount = 1;

        vector<Node *> newBuckets(newBucketCount, nullptr);

        for (size_t i = 0; i < m_buckets.size(); i++) {
            Node *cur = m_buckets[i];
            while (cur) {
                Node *next = cur->next;

                size_t newIndex = bucketIndexForKey(cur->key, newBucketCount);
                cur->next = newBuckets[newIndex];
                newBuckets[newIndex] = cur;

                cur = next;
            }
            m_buckets[i] = nullptr;
        }

        m_buckets.swap(newBuckets);
    }

    void ensureCapacityForInsert() {
        if (m_buckets.empty()) {
            m_buckets.assign(16, nullptr);
            return;
        }
        float load = static_cast<float>(m_size) / static_cast<float>(m_buckets.size());
        if (load > m_maxLoadFactor) {
            rehash(m_buckets.size() * 2);
        }
    }

public:
    explicit HashMap(size_t initialBucketCount = 16, float maxLoadFactor = 0.75f)
        : m_buckets(initialBucketCount < 1 ? 1 : initialBucketCount, nullptr),
          m_size(0),
          m_maxLoadFactor(maxLoadFactor),
          m_hasher(Hash()),
          m_keyEqual(KeyEqual()) {
        if (m_maxLoadFactor <= 0.0f) {
            m_maxLoadFactor = 0.75f;
        }
    }

    ~HashMap() {
        clear();
    }

    HashMap(const HashMap &) = delete;
    HashMap &operator=(const HashMap &) = delete;

    size_t size() const {
        return m_size;
    }

    bool isEmpty() const {
        return m_size == 0;
    }

    size_t bucketCount() const {
        return m_buckets.size();
    }

    float loadFactor() const {
        if (m_buckets.empty()) return 0.0f;
        return static_cast<float>(m_size) / static_cast<float>(m_buckets.size());
    }

    void clear() {
        for (size_t i = 0; i < m_buckets.size(); i++) {
            Node *cur = m_buckets[i];
            while (cur) {
                Node *next = cur->next;
                delete cur;
                cur = next;
            }
            m_buckets[i] = nullptr;
        }
        m_size = 0;
    }

    bool containsKey(const K &key) const {
        if (m_buckets.empty()) return false;
        size_t index = bucketIndexForKey(key, m_buckets.size());
        return findNode(key, index) != nullptr;
    }

    // 插入或更新：
    // - key 不存在：插入，返回 true
    // - key 已存在：更新 value，返回 false
    bool put(const K &key, const V &value) {
        ensureCapacityForInsert();
        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        if (node) {
            node->value = value;
            return false;
        }
        m_buckets[index] = new Node(key, value, m_buckets[index]);
        m_size++;
        ensureCapacityForInsert();
        return true;
    }

    bool put(K &&key, V &&value) {
        ensureCapacityForInsert();
        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        if (node) {
            node->value = std::move(value);
            return false;
        }
        m_buckets[index] = new Node(std::move(key), std::move(value), m_buckets[index]);
        m_size++;
        ensureCapacityForInsert();
        return true;
    }

    // 查找：存在则写入 outValue 并返回 true；否则返回 false
    bool get(const K &key, V &outValue) const {
        if (m_buckets.empty()) return false;
        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        if (!node) return false;
        outValue = node->value;
        return true;
    }

    // 查找指针（方便直接修改 value）：不存在返回 nullptr
    V *getPtr(const K &key) {
        if (m_buckets.empty()) return nullptr;
        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        return node ? &node->value : nullptr;
    }

    const V *getPtr(const K &key) const {
        if (m_buckets.empty()) return nullptr;
        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        return node ? &node->value : nullptr;
    }

    // 删除：存在则删除并返回 true，否则返回 false
    bool remove(const K &key) {
        if (m_buckets.empty()) return false;

        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *cur = m_buckets[index];
        Node *pre = nullptr;

        while (cur) {
            if (m_keyEqual(cur->key, key)) {
                if (pre) {
                    pre->next = cur->next;
                } else {
                    m_buckets[index] = cur->next;
                }
                delete cur;
                m_size--;
                return true;
            }
            pre = cur;
            cur = cur->next;
        }
        return false;
    }

    // 下标访问：不存在则插入默认值并返回引用（行为类似 std::unordered_map::operator[]）
    V &operator[](const K &key) {
        ensureCapacityForInsert();

        size_t index = bucketIndexForKey(key, m_buckets.size());
        Node *node = findNode(key, index);
        if (node) {
            return node->value;
        }

        m_buckets[index] = new Node(key, V(), m_buckets[index]);
        m_size++;
        ensureCapacityForInsert();
        return m_buckets[index]->value;
    }

    // 调试输出：展示每个桶链表长度（便于观察冲突与分布）
    string distribution() const {
        std::ostringstream oss;
        oss << "HashMap{size=" << m_size << ", buckets=" << m_buckets.size() << ", load=" << loadFactor() << "}\n";
        for (size_t i = 0; i < m_buckets.size(); i++) {
            size_t chainLen = 0;
            Node *cur = m_buckets[i];
            while (cur) {
                chainLen++;
                cur = cur->next;
            }
            oss << "[" << i << "]: " << chainLen << "\n";
        }
        return oss.str();
    }
};
