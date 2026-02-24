# 算法工程单元测试指南

## 📋 项目概述

本项目是一个算法与数据结构学习工程，包含多种经典算法实现和对应的单元测试。

## 🗂️ 测试结构

测试文件按照算法类型进行组织：

```
arithmeticTests/
├── Array/                          # 数组算法测试
│   ├── Array_FastSlowPointerTests.swift       # 快慢指针（删除重复、移除元素、移动零）
│   ├── Array_LeftRightPointerTests.swift      # 左右指针（两数之和、三数之和、回文）
│   └── Array_PrefixSumTests.swift             # 前缀和（区间和、子矩阵和）
│
├── LinkList/                       # 链表算法测试
│   ├── LinkList_MergeTests.swift              # 链表合并（两个有序链表、K个有序链表）
│   └── LinkList_AlgorithmTests.swift          # 链表算法（倒数第K个、中点、环检测、相交）
│
├── DataStructure/                  # 数据结构测试
│   ├── DataStructure_LRUCacheTests.swift      # LRU缓存
│   ├── DataStructure_LFUCacheTests.swift      # LFU缓存
│   └── DataStructure_HashMapTests.mm          # HashMap
│
└── LeetCode/                       # LeetCode题目测试
    └── LeetCode_0001_TwoSumTests.mm           # 两数之和
```

## 🎯 测试覆盖的算法

### 数组算法

#### 快慢指针
- ✅ 删除排序数组中的重复元素
- ✅ 移除数组中等于指定值的元素  
- ✅ 将所有0移到数组末尾

#### 左右指针
- ✅ 有序数组的两数之和
- ✅ 有序数组的三数之和
- ✅ 反转字符数组
- ✅ 判断回文串
- ✅ 最长回文子串

#### 前缀和数组
- ✅ 构建一维前缀和数组
- ✅ 查询区间和
- ✅ 构建二维前缀和矩阵
- ✅ 查询子矩阵和

### 链表算法

#### 链表合并
- ✅ 合并两个有序链表
- ✅ 合并K个有序链表（优先队列实现）

#### 链表基本算法
- ✅ 寻找链表倒数第K个节点（快慢指针）
- ✅ 寻找链表中点（快慢指针）
- ✅ 判断链表是否包含环并找出环起点（Floyd判圈算法）
- ✅ 判断两个链表是否相交并找出交点

### 数据结构

#### LRU缓存（Least Recently Used）
- ✅ O(1) 时间复杂度的 get 和 put 操作
- ✅ 使用哈希表+双向链表实现
- ✅ 淘汰最久未使用的元素

#### LFU缓存（Least Frequently Used）
- ✅ O(1) 时间复杂度的 get 和 put 操作
- ✅ 淘汰访问频率最低的元素
- ✅ 频率相同时淘汰最早访问的元素

#### HashMap
- ✅ 基本的 put、get、remove 操作
- ✅ 操作符重载支持

## 🚀 运行测试

### 方式1: 使用 Xcode Test Navigator（推荐）

1. 打开 Xcode
2. 使用快捷键 `Cmd + 6` 打开 Test Navigator
3. 点击任意测试类或测试方法左侧的 ▶️ 按钮运行

### 方式2: 使用命令行

```bash
# 运行所有 XCTest 单元测试
xcodebuild test -scheme arithmeticTests

# 运行主程序（包含内置Swift测试）
xcodebuild -scheme arithmetic build
./path/to/arithmetic
```

### 方式3: 运行主程序

```bash
cd /path/to/arithmetic
xcodebuild -scheme arithmetic
./Products/Debug/arithmetic
```

## 📊 测试统计

### 数组算法测试
- **Array_FastSlowPointerTests**: 21个测试用例
- **Array_LeftRightPointerTests**: 27个测试用例  
- **Array_PrefixSumTests**: 23个测试用例

### 链表算法测试
- **LinkList_MergeTests**: 15个测试用例
- **LinkList_AlgorithmTests**: 27个测试用例

### 数据结构测试
- **DataStructure_LRUCacheTests**: 26个测试用例
- **DataStructure_LFUCacheTests**: 22个测试用例
- **DataStructure_HashMapTests**: 2个测试用例

**总计**: 163+ 个测试用例

## 🎓 学习路径建议

### 初学者路径
1. 数组 - 快慢指针（最简单）
2. 数组 - 左右指针
3. 链表 - 合并操作
4. 链表 - 快慢指针算法

### 进阶路径
1. 数组 - 前缀和数组
2. 链表 - 环检测与相交检测
3. LRU缓存实现
4. LFU缓存实现

## 💡 测试最佳实践

### 命名规范
```swift
// 测试方法命名格式: test_功能_场景
func test_removeDuplicates_basic()           // 基本功能
func test_removeDuplicates_emptyArray()      // 边界情况
func test_removeElement_noMatch()            // 特殊情况
```

### 断言使用
```swift
XCTAssertEqual(actual, expected, "失败时的提示信息")
XCTAssertNil(result, "应为nil")
XCTAssertTrue(condition, "条件应为真")
```

### 测试覆盖
每个算法至少包含：
- ✅ 基本功能测试
- ✅ 边界条件测试（空、单元素、最大值）
- ✅ 特殊场景测试

## 🔧 测试工具类

### 链表测试辅助
```swift
// 构建测试链表
let list = MergeSortedLists.buildList([1, 2, 3, 4, 5])

// 转换为数组验证
let array = MergeSortedLists.toArray(list)
XCTAssertEqual(array, [1, 2, 3, 4, 5])
```

## 📚 参考资源

- [LeetCode算法题库](https://leetcode.com)
- [labuladong算法小抄](https://labuladong.github.io/algo/)
- Apple XCTest 文档

## 🤝 贡献指南

添加新算法测试时：
1. 在对应目录创建测试文件
2. 继承自 `XCTestCase`
3. 遵循命名规范
4. 提供充分的测试覆盖
5. 添加注释说明算法思想

## 📝 更新日志

### v2.0 (2026-02-06)
- ✅ 重构测试结构，按算法类型组织
- ✅ 新增 163+ 个 XCTest 单元测试
- ✅ 添加 LRU/LFU 缓存完整测试
- ✅ 清理 main.mm 手动测试代码
- ✅ 改进测试可维护性

### v1.0 (2019-2021)
- 初始版本，包含基础算法实现
