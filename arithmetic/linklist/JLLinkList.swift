import Foundation

// Singly linked node keeps only a next pointer.
public final class JLSinglyLinkNode<Element: Equatable> {
    public var value: Element
    public var next: JLSinglyLinkNode?

    public init(_ value: Element, next: JLSinglyLinkNode? = nil) {
        self.value = value
        self.next = next
    }
}
extension JLSinglyLinkNode: Equatable {

    public static func == (lhs: JLSinglyLinkNode, rhs: JLSinglyLinkNode) -> Bool {
        return lhs.value == rhs.value && lhs.next == rhs.next
    }
}

// Doubly linked node tracks both directions.
public final class JLDoublyLinkNode<Element> {
    public var value: Element
    public weak var prev: JLDoublyLinkNode?
    public var next: JLDoublyLinkNode?

    public init(_ value: Element, prev: JLDoublyLinkNode? = nil, next: JLDoublyLinkNode? = nil) {
        self.value = value
        self.prev = prev
        self.next = next
    }
}

// Doubly linked list implementation mirroring the old Objective-C API surface.
public final class JLLinkList<Element> {
    public private(set) var head: JLDoublyLinkNode<Element>?
    private weak var tail: JLDoublyLinkNode<Element>?
    public private(set) var count: Int = 0

    public var length: Int { count }

    @discardableResult
    public func append(_ value: Element) -> JLDoublyLinkNode<Element> {
        let node = JLDoublyLinkNode(value)
        addNode(node)
        return node
    }

    public func addNode(_ node: JLDoublyLinkNode<Element>) {
        insertNode(node, at: count)
    }

    public func insertNode(_ node: JLDoublyLinkNode<Element>, at index: Int) {
        guard index >= 0, index <= count else { return }
        detach(node)

        if index == count {
            appendToTail(node)
            return
        }

        if index == 0 {
            node.next = head
            head?.prev = node
            head = node
            if tail == nil { tail = node }
            count += 1
            return
        }

        var current = head
        for _ in 0..<(index - 1) { current = current?.next }
        guard let previous = current else { return }

        let nextNode = previous.next
        previous.next = node
        node.prev = previous
        node.next = nextNode
        nextNode?.prev = node
        count += 1
    }

    @discardableResult
    public func removeNode(_ node: JLDoublyLinkNode<Element>) -> Element? {
        guard let target = locate(node) else { return nil }
        let prevNode = target.prev
        let nextNode = target.next

        prevNode?.next = nextNode
        nextNode?.prev = prevNode

        if target === head { head = nextNode }
        if target === tail { tail = prevNode }

        count -= 1
        let value = target.value
        detach(target)
        return value
    }

    private func appendToTail(_ node: JLDoublyLinkNode<Element>) {
        if let currentTail = tail {
            currentTail.next = node
            node.prev = currentTail
            tail = node
        } else {
            head = node
            tail = node
        }
        count += 1
    }

    private func detach(_ node: JLDoublyLinkNode<Element>) {
        node.prev = nil
        node.next = nil
    }

    private func locate(_ node: JLDoublyLinkNode<Element>) -> JLDoublyLinkNode<Element>? {
        var cursor = head
        while let current = cursor {
            if current === node { return current }
            cursor = current.next
        }
        return nil
    }
}
