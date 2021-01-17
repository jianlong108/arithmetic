//
//  main.cpp
//  算法
//
//  Created by wangjianlong on 2019/2/14.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "1-两数之和.hpp"
#include "2- 两数相加.hpp"
#include "3-无重复字符的最长子串.hpp"

using namespace std;

//int main(int argc, const char * argv[]) {
////    1.两数之和
////    vector<int>sourceArray{2,7,11,15};
////    int target = 9;
////    vector<int>v = twoSum_hash(sourceArray,target);
////    cout << v[0] << " " << v[1] << endl;
//
//    string s = string("aabcc");
////    cout << lengthOfLongestSubstring(s) << endl;
//    cout << charMap_lengthOfLongestSubstring(s) << endl;
//    return 0;
//}

//int main(int argc, const char * argv[]) {
//    set<int>s;
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        int x;
//        cin>>x;
//        s.insert (x);
//    }
//    set<int>::iterator it;
//    for(it=s.begin ();it!=s.end ();it++)
//    {
//        printf("%d\n",*it);
//    }
//
//    //s.end()没有值
//     cout<<"s.begain()   "<<*s.begin ()<<endl;
//    //lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
//    cout<<"lower_buond  3  "<<*s.lower_bound (3)<<endl;
//
//    //upper_bound()--返回大于某个值元素的迭代器
//    cout<<"upper_bound  3  "<<*s.upper_bound (3)<<endl;
//
//    //find()--返回一个指向被查找到元素的迭代器
//    cout<<"find()  3   "<<*s.find (3)<<endl;
//
//    cout<<"s.size()  "<<s.size ()<<endl;
//    return 0;
//}

 //
 //  main.cpp
 //  1-1链表
 //
 //  Created by Wangjianlong on 2019/2/17.
 //  Copyright © 2019 JL.Com. All rights reserved.
 //

#include <iostream>
#include "SingleLinkList.hpp"
#include "SingleCircleLinkList.hpp"
#include "CircleLinkList.hpp"
#include "Stack.hpp"
//#include "string.hpp"
//#include "Tree.hpp"
#include "ArrayList.hpp"
#include "LinkList.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
#include "CircleQueue.hpp"
#include "CircleDeque.hpp"

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
//  SingleLinkList *list = new SingleLinkList(108);
    SingleCircleLinkList<int> *list = new SingleCircleLinkList<int>();

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
//     CircleQueue<int> queue = CircleQueue<int>();
//    for (int i = 1; i<11; i++) {
//        queue.enQueue(i);
//    }
//     cout<<queue.description()<<endl;
//     queue.enQueue(88);
//     cout<<queue.description()<<endl;
//     queue.deQueue();
//     cout<<queue.description()<<endl;
//     cout<<queue.frontElement()<<endl;
     
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


 int main(int argc, const char * argv[]) {
     {
//         singlelistTest();
//         arrayListTest();
//         singleCyclelistTest();
//         CyclelistTest();
//         LinklistTest();
//         stackTest();
//         DequeTest();
         circleQueueTest();
     }
     return 0;
     /*
     LinkList head;
     creatLinkListTail(&head, 3);
     LinkList p = head->next;
     while (p) {
         cout << p->val << endl;
         p = p->next;
     }
     int value= 108;
     int i = 2;
 //    int status = getElement(head, i, &value);
 //    cout << "状态"<< status << ";" <<i << "位置处的值为" << value << endl;
 //    deleteLinkList(&head);
     cout << "---------------------"<< endl;
     p = head->next;
     //在第i==2个结点之前插入数据108
     insertList(&head, i, value);
     while (p) {
         cout << p->val << endl;
         p = p->next;
     }
     cout << "---------------------"<< endl;
     p = head->next;
     //删除第i==3个结点之前插入数据
     deletEleList(&head, 3, &value);
     while (p) {
         cout << p->val << endl;
         p = p->next;
     }
     cout << "---------------------"<< endl;
 //    string s = getTmpString(string("123abc4"));
 //    cout << s << endl;
     string s = string("123abc4acd");
     string t = string("abc");
     cout << t << "在主串："<<s <<"中的位置：" << indexSubString(s, t, 0) << endl;
     cout << "---------------------"<< endl;
     
     BiTree tree = BiTree();
     creatBigTree(&tree);
     
     preOrderTraverse(tree);
     
      return 0;
      */
 }

