import Foundation

@_cdecl("run_merge_sorted_lists_tests")
public func run_merge_sorted_lists_tests() {
    MergeSortedLists.Tests.run()
}

// Merge two ascending singly linked lists built from JLSinglyLinkNode.
public enum MergeSortedLists {
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

    // Lightweight unit test runner. Call MergeTwoSortedLists.Tests.run() from main when desired.
    public struct Tests {
        public static func run() {
            testMergeBasic()
            testMergeWithEmpty()
            testMergeSingleElement()
            testMergeKBasic()
            testMergeKWithEmpties()
            testMergeKAllEmpty()
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
