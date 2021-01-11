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
 #include "Stack.hpp"
 #include "string.hpp"
 #include "Tree.hpp"

 using namespace std;

 int main(int argc, const char * argv[]) {
     {
//         SingleLinkList *list = new SingleLinkList(108);
         SingleLinkList<int> *list = new SingleLinkList<int>(108);
  
//         list->addNodeToHead(3);
         list->addNodeToTail(6);
         list->printFromHeadToTail();
         int val = -1;
         Status s = list->getElement(2, &val);
         cout << s << ":" <<val << endl;
         
         val = -1;
         s = list->getElement(8, &val);
         cout << s << ":" <<val << endl;
         
         list->insertList(3, 99);
         list->printFromHeadToTail();
         val = -1;
         list->deletEleList(4, &val);
         list->printFromHeadToTail();
//         list->deleteLinkList();
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

