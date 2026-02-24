#import <XCTest/XCTest.h>

#include "HashMap.hpp"

@interface DataStructure_HashMapTests : XCTestCase
@end

@implementation DataStructure_HashMapTests

- (void)test_put_get_remove_basic {
    HashMap<std::string, int> m;

    XCTAssertTrue(m.isEmpty());
    XCTAssertEqual((size_t)0, m.size());

    XCTAssertTrue(m.put("a", 1));
    XCTAssertTrue(m.put("b", 2));
    XCTAssertFalse(m.put("a", 3)); // update

    int v = 0;
    XCTAssertTrue(m.get("a", v));
    XCTAssertEqual(3, v);

    XCTAssertTrue(m.containsKey("b"));
    XCTAssertTrue(m.remove("b"));
    XCTAssertFalse(m.containsKey("b"));
    XCTAssertFalse(m.remove("b"));
}

- (void)test_operator_brackets_inserts_default {
    HashMap<std::string, int> m;

    XCTAssertFalse(m.containsKey("k"));
    m["k"] += 10;
    XCTAssertTrue(m.containsKey("k"));

    int v = 0;
    XCTAssertTrue(m.get("k", v));
    XCTAssertEqual(10, v);
}

@end
