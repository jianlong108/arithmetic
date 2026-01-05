import Foundation

// Shared helpers for building and inspecting JLSinglyLinkNode-based lists in tests.
public enum LinkListTestHelpers {
    // Build a list and return the head node.
    public static func buildList<T>(_ values: [T]) -> JLSinglyLinkNode<T>? {
        return buildListWithTail(values).head
    }

    // Build a list and return both head and tail nodes for cases needing tail stitching.
    public static func buildListWithTail<T>(_ values: [T]) -> (head: JLSinglyLinkNode<T>?, tail: JLSinglyLinkNode<T>?) {
        guard let first = values.first else { return (nil, nil) }
        let head = JLSinglyLinkNode(first)
        var cursor = head
        for value in values.dropFirst() {
            let node = JLSinglyLinkNode(value)
            cursor.next = node
            cursor = node
        }
        return (head, cursor)
    }

    // Convert a list back into an array for easy assertions.
    public static func toArray<T>(_ head: JLSinglyLinkNode<T>?) -> [T] {
        var result: [T] = []
        var cursor = head
        while let node = cursor {
            result.append(node.value)
            cursor = node.next
        }
        return result
    }
}
