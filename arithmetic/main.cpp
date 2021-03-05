//
//  main.cpp
//  算法
//
//  Created by wangjianlong on 2019/2/14.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#include <iostream>

#include "1-两数之和.hpp"
#include "2- 两数相加.hpp"
#include "3-无重复字符的最长子串.hpp"
#include "4-接雨水.hpp"
#include "电脑联通.hpp"
#include "AboutLinkList.hpp"

#include "SingleLinkList.hpp"
#include "SingleCircleLinkList.hpp"
#include "CircleLinkList.hpp"
#include "Stack.hpp"

#include "ArrayList.hpp"
#include "LinkList.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
#include "CircleQueue.hpp"
#include "CircleDeque.hpp"
#include "QuickFind.hpp"
#include "QuickUnion.hpp"
#include "BindaryTree.hpp"
#include "DynamicPlanning.hpp"
#include "ArrayAndString.hpp"



using namespace std;

void arrayListTest()
{
    ArrayList<int> *arr = new ArrayList<int>(2);
    for (int i = 1; i<=20; i++) {
        arr->add(i);
    }
    cout << arr->toString() << endl;
    arr->remove(5);

    cout << arr->toString() << endl;
    arr->get(6);
    delete arr;
}

void singlelistTest()
{
//  SingleLinkList *list = new SingleLinkList(108);
    SingleLinkList<int> *list = new SingleLinkList<int>();

//  list->addNodeToHead(3);
    list->add(6);
    list->add(8);
    list->add(9);
    list->addNodeToHead(11);
    list->addNodeToHead(14);
    list->addNodeToHead(17);
    cout<<list->toString()<<endl;
    int val = list->get(2);
    cout << ":" <<val << endl;

//    val = list->get(8);
//    cout << ":" <<val << endl;

    list->addAtIndex(1, 99);
    cout<<list->toString()<<endl;
    list->remove(0);
    cout<<list->toString()<<endl;
    list->remove(5);
    cout<<list->toString()<<endl;
//  list->deleteLinkList();

    list->clear();
    delete list;
}
void singleCyclelistTest()
{
    SingleCircleLinkList<int> *list = new SingleCircleLinkList<int>();
    list->add(6);
    list->add(8);
    list->add(9);
    list->addNodeToHead(11);
    list->addNodeToHead(14);
    list->addNodeToHead(17);
    cout<<list->toString()<<endl;
    int val = list->get(2);
    cout << ":" <<val << endl;

    list->addAtIndex(1, 99);
    cout<<list->toString()<<endl;
    list->remove(0);
    cout<<list->toString()<<endl;
    list->remove(5);
    cout<<list->toString()<<endl;

    list->clear();
    delete list;
}

void CyclelistTest()
{
    CircleLinkList<int> *list = new CircleLinkList<int>();
    list->add(6);
    list->add(8);
    list->add(9);
    cout<<list->description()<<endl;
    list->addNodeToHead(11);
    list->addNodeToHead(14);
    list->addNodeToHead(17);
    cout<<list->description()<<endl;
    int val = list->get(2);
    cout << ":" <<val << endl;

    list->addAtIndex(1, 99);
    cout<<list->description()<<endl;
    list->remove(0);
    cout<<list->description()<<endl;
    list->remove(5);
    cout<<list->description()<<endl;

    list->clear();
    delete list;
}

void LinklistTest()
{
    LinkList<int> list = LinkList<int>();
    list.add(6);
    list.add(8);
    list.add(9);
    list.addAtIndex(1, 7);
    cout<<list.description()<<endl;
    list.addNodeToHead(11);
    list.addNodeToHead(14);
    list.addNodeToHead(17);
    cout<<list.description()<<endl;
    int val = list.get(2);
    cout << "index:2 == " <<val << endl;

    list.addAtIndex(1, 99);
    cout<<list.description()<<endl;
    list.remove(0);
    cout<<list.description()<<endl;
    list.remove(5);
    cout<<list.description()<<endl;

    list.clear();
}

void stackTest()
{
    Stack<int> *stack = new Stack<int>();
    for (int i = 1; i<=20; i++) {
        stack->push(i);
    }
    cout << stack->top() << endl;
    cout << stack->description() << endl;
    cout << stack->pop() << endl;

    cout << stack->pop() << endl;
    cout << stack->description() << endl;
    delete stack;
}

void DequeTest()
{
     Queue<int> queue = Queue<int>();
     queue.enQueue(1);
     queue.enQueue(2);
     queue.enQueue(3);
     cout<<queue.description()<<endl;
     queue.deQueue();
     cout<<queue.description()<<endl;
     cout<<queue.front()<<endl;

     Deque<int> deque = Deque<int>();
     deque.enQueueFront(1);
     deque.enQueueFront(2);
     deque.enQueueRear(3);
     cout<<deque.description()<<endl;
     deque.deQueueRear();
     cout<<deque.description()<<endl;
     cout<<deque.front()<<endl;
}

void circleQueueTest()
{
    CircleDeque<int> deque = CircleDeque<int>();
    for (int i = 1; i<9; i++) {
        deque.enQueueFront(i);
    }
     cout<<deque.description()<<endl;
     deque.enQueue(88);
     cout<<deque.description()<<endl;
     deque.deQueue();
     cout<<deque.description()<<endl;
     cout<<deque.frontElement()<<endl;
}

void charTest()
{
    //ISO C++11 does not allow conversion from string literal to 'char *'
//    char const*a = "abcd";
    char *a = "abcd";
    char s[] = "123";

    //把字符串加到指针所指的字串上去，出现段错误，本质原因：*d="0123456789"存放在常量区，是无法修的。而数组是存放在栈中，是可以修改的
//    strcat(s, a);
//    printf("%s\n",s);
    strcat(a, s);
    printf("%s\n",a);
}

void quickFindTest()
{
    QuickFind qf = QuickFind(100);
    qf.unionEle(0, 1);
    qf.unionEle(0, 3);
    qf.unionEle(0, 4);
    qf.unionEle(2, 3);
    qf.unionEle(2, 5);
    qf.unionEle(6, 7);
    qf.unionEle(8, 10);
    qf.unionEle(9, 10);
    qf.unionEle(9, 11);
    cout << qf.isSame(0, 6) << endl;
    cout << qf.isSame(0, 2) << endl;
    qf.unionEle(0, 6);
    cout << qf.isSame(3, 7) << endl;
}

void quickUnionTest()
{
    QuickUnion qf = QuickUnion(100);
    qf.unionEle(0, 1);
    qf.unionEle(0, 3);
    qf.unionEle(0, 4);
    qf.unionEle(2, 3);
    qf.unionEle(2, 5);
    qf.unionEle(6, 7);
    qf.unionEle(8, 10);
    qf.unionEle(9, 10);
    qf.unionEle(9, 11);
    cout << qf.find(0) << endl;
    cout << qf.isSame(0, 6) << endl;
    cout << qf.isSame(0, 2) << endl;
    qf.unionEle(0, 6);
    cout << qf.isSame(3, 7) << endl;
}


int main(int argc, const char * argv[]) {
    {
//        cout << "单向链表begin" << endl;
//         singlelistTest();
//        cout << "arrayListbegin" << endl;
//         arrayListTest();
//        cout << "单向循环链表begin" << endl;
//         singleCyclelistTest();
//        cout << "循环链表begin" << endl;
//         CyclelistTest();
//        cout << "" << endl;
//         LinklistTest();
//        cout << "" << endl;
//         stackTest();
//        cout << "" << endl;
//         DequeTest();
////        cout << "目前有问题,需要调试" << endl;
////         circleQueueTest();
//        cout << "二选一" << endl;
//        vector<int>heights{0,1,0,2,1,0,1,3,2,1,2,1};
//        cout << trap(heights) << endl;
////        vector<int>heights{4,2,0,3,2,5};
////        cout << trap(heights) << endl;
//
//       cout << "" << endl;
//        quickFindTest();
//        cout << "" << endl;
//        quickUnionTest();
//        TestReverseList();
//        TestPartitionList();
//        TestaddTwoNumbers();
//        TestdetectCycle();
//        TestSortList();
//        TestRotateRight();
//        TestoddEvenList();
//        TestcopyRandomList();
//        TestUniquePaths();
//        TestFindNumberIn2DArray();
//        TestreplaceSpace();
//        TestminArray();
//        TestExchange();
        TestSpiralOrder();
     }
     return 0;
}

