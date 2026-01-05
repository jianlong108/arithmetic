import Foundation

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
        /*
        var left = lhs
        var right = rhs
        var leftCount = 0
        var rightCount = 0
        while let l = left {
            leftCount += 1
            left = l.next
        }

        while let r = right {
            rightCount += 1
            right = r.next
        }

        left = lhs
        right = rhs

        if leftCount > rightCount {
            for _ in 0..<(leftCount - rightCount) {
                left = left?.next
            }
        } else if rightCount > leftCount {
            for _ in 0..<(rightCount - leftCount) {
                right = right?.next
            }
        }

        while let l = left, let r = right {
            if l === r {
                return l
            }
            left = l.next
            right = r.next
        }

        return nil
        */
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

