import Foundation

@_cdecl("run_merge_sorted_lists_tests")
public func run_merge_sorted_lists_tests() {
    MergeSortedLists.Tests.run()
}
/*
1 . 合 并 两 个 有 序 链 表 。
2 . 合 并 k 个 有 序 链 表 。
3 . 寻 找 单 链 表 的 倒 数 第 k 个 节 点 。
4 . 寻 找 单 链 表 的 中 点 。
5 . 判 断 单 链 表 是 否 包 含 环 并 找 出 环 起 点 。
6 . 判 断 两 个 单 链 表 是 否 相 交 并 找 出 交 点
*/
// Merge two ascending singly linked lists built from JLSinglyLinkNode.
public enum MergeSortedLists {
    // 合并两个有序链表,返回合并后的链表头节点.
    public static func merge<T: Comparable>(_ lhs: JLSinglyLinkNode<T>?, _ rhs: JLSinglyLinkNode<T>?) -> JLSinglyLinkNode<T>? {
        var left = lhs
        var right = rhs

        var head: JLSinglyLinkNode<T>?
        var tail: JLSinglyLinkNode<T>?

        func push(_ node: JLSinglyLinkNode<T>) {
            if head == nil {
                head = node
                tail = node
            } else {
                tail?.next = node
                tail = node
            }
        }

        while let l = left, let r = right {
            if l.value <= r.value {
                left = l.next
                l.next = nil
                push(l)
            } else {
                right = r.next
                r.next = nil
                push(r)
            }
        }

        while let l = left {
            left = l.next
            l.next = nil
            push(l)
        }

        while let r = right {
            right = r.next
            r.next = nil
            push(r)
        }

        return head
    }

    // Merge k ascending singly linked lists using a min-heap (priority queue).
    // 合并k个有序链表,返回合并后的链表头节点.
    public static func mergeK<T: Comparable>(_ lists: [JLSinglyLinkNode<T>?]) -> JLSinglyLinkNode<T>? {
        var heap = MinHeap<Entry<T>>()
        for head in lists {
            if let node = head {
                heap.push(Entry(node))
            }
        }

        var resultHead: JLSinglyLinkNode<T>?
        var resultTail: JLSinglyLinkNode<T>?

        func pushResult(_ node: JLSinglyLinkNode<T>) {
            if resultHead == nil {
                resultHead = node
                resultTail = node
            } else {
                resultTail?.next = node
                resultTail = node
            }
        }

        while let entry = heap.pop() {
            let node = entry.node
            let next = node.next
            node.next = nil
            pushResult(node)
            if let next = next {
                heap.push(Entry(next))
            }
        }

        return resultHead
    }

    // Build a linked list from an array for testing convenience.
    public static func buildList<T>(_ values: [T]) -> JLSinglyLinkNode<T>? {
        return LinkListTestHelpers.buildList(values)
    }

    // Convert a linked list back to an array for assertions/inspection.
    public static func toArray<T>(_ head: JLSinglyLinkNode<T>?) -> [T] {
        return LinkListTestHelpers.toArray(head)
    }

    // 寻 找 单 链 表 的 倒 数 第 k 个 节 点 (k 从 1 开始)。
    public static func kthFromEnd<T>(_ head: JLSinglyLinkNode<T>?, k: Int) -> JLSinglyLinkNode<T>? {
        guard k > 0 else { return nil }
        var fast = head
        for _ in 0..<k {
            guard let next = fast else { return nil }
            fast = next.next
        }

        var slow = head
        while fast != nil {
            fast = fast?.next
            slow = slow?.next
        }
        return slow
    }

    // 寻 找 单 链 表 的 中 点，偶数长度返回第二个中点。
    public static func middleNode<T>(_ head: JLSinglyLinkNode<T>?) -> JLSinglyLinkNode<T>? {
        var slow = head
        var fast = head
        while let f = fast, let next = f.next {
            slow = slow?.next
            fast = next.next
        }
        return slow
    }

    // 判 断 单 链 表 是 否 包 含 环 并 找 出 环 起 点。
    public static func detectCycleStart<T>(_ head: JLSinglyLinkNode<T>?) -> JLSinglyLinkNode<T>? {
        var slow = head
        var fast = head

        while let f = fast, let next = f.next {
            slow = slow?.next
            fast = next.next
            if slow === fast { break }
        }

        guard let meeting = slow, let _ = fast, slow === fast else { return nil }

        var ptr1 = head
        var ptr2: JLSinglyLinkNode<T>? = meeting
        while ptr1 !== ptr2 {
            ptr1 = ptr1?.next
            ptr2 = ptr2?.next
        }
        return ptr1
    }

    // 判 断 两 个 单 链 表 是 否 相 交 并 找 出 交 点。
    public static func intersectionNode<T>(_ lhs: JLSinglyLinkNode<T>?, _ rhs: JLSinglyLinkNode<T>?) -> JLSinglyLinkNode<T>? {
        return GetInteractLinkList.getIntersectNode(lhs, rhs)
    }

    // Lightweight unit test runner. Call MergeTwoSortedLists.Tests.run() from main when desired.
    public struct Tests {
        public static func run() {
            testMergeBasic()
            testMergeWithEmpty()
            testMergeSingleElement()
            testMergeKBasic()
            testMergeKWithEmpties()
            testMergeKAllEmpty()
            testKthFromEnd()
            testMiddleNode()
            testDetectCycle()
            testIntersection()
        }

        private static func testMergeBasic() {
            let l1 = buildList([1, 2, 4])
            let l2 = buildList([1, 3, 4])
            let merged = merge(l1, l2)
            print("testMergeBasic ->", toArray(merged))
            assert(toArray(merged) == [1, 1, 2, 3, 4, 4], "merge basic failed")
        }

        private static func testMergeWithEmpty() {
            let l1 = buildList([0, 2, 5])
            let merged = merge(l1, nil)
            print("testMergeWithEmpty ->", toArray(merged))
            assert(toArray(merged) == [0, 2, 5], "merge empty failed")
        }

        private static func testMergeSingleElement() {
            let l1 = buildList([1])
            let l2 = buildList([2])
            let merged = merge(l1, l2)
            print("testMergeSingleElement ->", toArray(merged))
            assert(toArray(merged) == [1, 2], "merge single element failed")
        }

        private static func testMergeKBasic() {
            let a = buildList([1, 4, 5])
            let b = buildList([1, 3, 4])
            let c = buildList([2, 6])
            let merged = mergeK([a, b, c])
            print("testMergeKBasic ->", toArray(merged))
            assert(toArray(merged) == [1, 1, 2, 3, 4, 4, 5, 6], "mergeK basic failed")
        }

        private static func testMergeKWithEmpties() {
            let a = buildList([0])
            let merged = mergeK([a, nil, nil])
            print("testMergeKWithEmpties ->", toArray(merged))
            assert(toArray(merged) == [0], "mergeK with empties failed")
        }

        private static func testMergeKAllEmpty() {
            let lists: [JLSinglyLinkNode<Int>?] = [nil, nil]
            let merged = mergeK(lists)
            print("testMergeKAllEmpty ->", toArray(merged))
            assert(toArray(merged).isEmpty, "mergeK all empty failed")
        }

        private static func testKthFromEnd() {
            let head = buildList([1, 2, 3, 4, 5])
            let k2 = kthFromEnd(head, k: 2)
            let k1 = kthFromEnd(head, k: 1)
            let k5 = kthFromEnd(head, k: 5)
            let k6 = kthFromEnd(head, k: 6)
            print("testKthFromEnd ->", k2?.value as Any, k1?.value as Any, k5?.value as Any, k6 as Any)
            assert(k2?.value == 4, "kthFromEnd k=2 failed")
            assert(k1?.value == 5, "kthFromEnd k=1 failed")
            assert(k5?.value == 1, "kthFromEnd k=5 failed")
            assert(k6 == nil, "kthFromEnd k>length should be nil")
        }

        private static func testMiddleNode() {
            let odd = buildList([1, 2, 3, 4, 5])
            let even = buildList([1, 2, 3, 4])
            let middleOdd = middleNode(odd)
            let middleEven = middleNode(even)
            print("testMiddleNode ->", middleOdd?.value as Any, middleEven?.value as Any)
            assert(middleOdd?.value == 3, "middle of odd list failed")
            assert(middleEven?.value == 3, "middle of even list should return second middle")
        }

        private static func testDetectCycle() {
            let cycle = buildCyclicList([1, 2, 3, 4, 5], entryIndex: 2)
            let entry = detectCycleStart(cycle)
            let noCycle = buildList([1, 2, 3])
            let none = detectCycleStart(noCycle)
            print("testDetectCycle ->", entry?.value as Any, none as Any)
            assert(entry?.value == 3, "cycle entry should be value 3")
            assert(none == nil, "no cycle should return nil")
        }

        private static func testIntersection() {
            let shared = buildList([7, 8, 9])

            let aHead = buildList([1, 2, 3])
            var aTail = aHead
            while aTail?.next != nil { aTail = aTail?.next }
            aTail?.next = shared

            let bHead = buildList([4, 5])
            var bTail = bHead
            while bTail?.next != nil { bTail = bTail?.next }
            bTail?.next = shared

            let node = intersectionNode(aHead, bHead)
            print("testIntersection ->", node?.value as Any)
            assert(node === shared, "should detect shared segment head")
        }

        // Build a cyclic list where entryIndex points to the node where tail connects.
        private static func buildCyclicList<T>(_ values: [T], entryIndex: Int) -> JLSinglyLinkNode<T>? {
            guard let head = buildList(values) else { return nil }
            guard entryIndex >= 0 else { return head }
            var cursor = head
            var entry: JLSinglyLinkNode<T>?
            var idx = 0
            while cursor.next != nil {
                if idx == entryIndex { entry = cursor }
                cursor = cursor.next!
                idx += 1
            }
            if idx == entryIndex { entry = cursor }
            cursor.next = entry
            return head
        }
    }
}

// MARK: - Private helpers

private struct Entry<T: Comparable>: Comparable {
    let node: JLSinglyLinkNode<T>

    init(_ node: JLSinglyLinkNode<T>) {
        self.node = node
    }

    static func < (lhs: Entry<T>, rhs: Entry<T>) -> Bool {
        lhs.node.value < rhs.node.value
    }
}
// todo: 记得学习最小锥
// Simple binary min-heap.
private struct MinHeap<Element: Comparable> {
    private var storage: [Element] = []

    var isEmpty: Bool { storage.isEmpty }

    mutating func push(_ element: Element) {
        storage.append(element)
        siftUp(from: storage.count - 1)
    }

    mutating func pop() -> Element? {
        guard !storage.isEmpty else { return nil }
        if storage.count == 1 { return storage.removeLast() }
        let root = storage[0]
        storage[0] = storage.removeLast()
        siftDown(from: 0)
        return root
    }

    private mutating func siftUp(from index: Int) {
        var child = index
        var parent = (child - 1) / 2
        while child > 0 && storage[child] < storage[parent] {
            storage.swapAt(child, parent)
            child = parent
            parent = (child - 1) / 2
        }
    }

    private mutating func siftDown(from index: Int) {
        var parent = index
        let count = storage.count
        while true {
            let left = parent * 2 + 1
            let right = left + 1
            var candidate = parent
            if left < count && storage[left] < storage[candidate] {
                candidate = left
            }
            if right < count && storage[right] < storage[candidate] {
                candidate = right
            }
            if candidate == parent { return }
            storage.swapAt(parent, candidate)
            parent = candidate
        }
    }
}


@_cdecl("run_get_interact_link_list_tests")

public func run_get_interact_link_list_tests() {
    GetInteractLinkList.Tests.run()
}

// Get the intersecting linked list node of two singly linked lists built from JLSinglyLinkNode.
public enum GetInteractLinkList {
    public static func getIntersectNode<T>(_ lhs: JLSinglyLinkNode<T>?, _ rhs: JLSinglyLinkNode<T>?) -> JLSinglyLinkNode<T>? {
        var left = lhs
        var right = rhs

        while left !== right {
            left = left == nil ? rhs : left?.next
            right = right == nil ? lhs : right?.next
        }
        return left
    }

    // Lightweight unit tests for intersection detection.
    public struct Tests {
        public static func run() {
            testIntersectionInMiddle()
            testIntersectionAtHead()
            testNoIntersection()
            testOneEmptyList()
            testIdenticalValuesButDisjoint()
        }

        private static func testIntersectionInMiddle() {
            let (a, b, sharedHead) = buildIntersectingLists(prefixA: [1, 2, 3], prefixB: [7, 8], common: [9, 10, 11])
            let node = getIntersectNode(a, b)
            print("testIntersectionInMiddle ->", node?.value as Any, LinkListTestHelpers.toArray(node))
            assert(node === sharedHead, "expected intersection at shared segment head")
        }

        private static func testIntersectionAtHead() {
            let (a, b, sharedHead) = buildIntersectingLists(prefixA: [], prefixB: [], common: [5, 6])
            let node = getIntersectNode(a, b)
            print("testIntersectionAtHead ->", node?.value as Any, LinkListTestHelpers.toArray(node))
            assert(node === sharedHead, "expected intersection starting at head")
        }

        private static func testNoIntersection() {
            let a = LinkListTestHelpers.buildList([1, 3, 5])
            let b = LinkListTestHelpers.buildList([2, 4, 6])
            let node = getIntersectNode(a, b)
            print("testNoIntersection ->", node as Any)
            assert(node == nil, "expected no intersection")
        }

        private static func testOneEmptyList() {
            let b = LinkListTestHelpers.buildList([1, 2, 3])
            let node = getIntersectNode(nil as JLSinglyLinkNode<Int>?, b)
            print("testOneEmptyList ->", node as Any)
            assert(node == nil, "expected nil when one list is empty")
        }

        private static func testIdenticalValuesButDisjoint() {
            let a = LinkListTestHelpers.buildList([1, 2, 3])
            let b = LinkListTestHelpers.buildList([1, 2, 3])
            let node = getIntersectNode(a, b)
            print("testIdenticalValuesButDisjoint ->", node as Any)
            assert(node == nil, "lists with identical values but disjoint nodes should not intersect")
        }
    }

    // MARK: - Private helpers

    private static func buildIntersectingLists<T>(prefixA: [T], prefixB: [T], common: [T]) -> (JLSinglyLinkNode<T>?, JLSinglyLinkNode<T>?, JLSinglyLinkNode<T>?) {
        let (commonHead, commonTail) = LinkListTestHelpers.buildListWithTail(common)

        let (headA, tailA) = LinkListTestHelpers.buildListWithTail(prefixA)
        if let tailA = tailA {
            tailA.next = commonHead
        }

        let (headB, tailB) = LinkListTestHelpers.buildListWithTail(prefixB)
        if let tailB = tailB {
            tailB.next = commonHead
        }

        let finalHeadA = headA ?? commonHead
        let finalHeadB = headB ?? commonHead

        // If common is empty, ensure we don't fabricate an intersection.
        if commonHead == nil {
            return (finalHeadA, finalHeadB, nil)
        }

        return (finalHeadA, finalHeadB, commonHead ?? commonTail)
    }
}