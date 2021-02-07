//
//  3-无重复字符的最长子串.hpp
//  算法
//
//  Created by wangjianlong on 2019/2/18.
//  Copyright © 2019 wangjianlong. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 
 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 输出：6

 */

//单调栈
 int trap(vector<int> &height) {
     stack<int> s;
     
     int water = 0;
     //特殊情况
     if(height.size() <3){
         return 0;
     }
     for(int i = 0; i < height.size(); i++){
         while(!s.empty() && height[i] > height[s.top()]){
             //栈顶元素
             int popnum = s.top();
             s.pop();
             //相同元素的情况例1，1
             while(!s.empty() && height[popnum] == height[s.top()]){
                 s.pop();
             }
             //计算该层的水的单位
             if(!s.empty()){
                 int temp = height[s.top()];//栈顶元素值
                 //高
                 int hig = min(temp-height[popnum],height[i]-height[popnum]);
                 //宽
                 int wid = i-s.top()-1;
                 water +=hig * wid;
             }

         }
         //这里入栈的是索引
         s.push(i);
     }
     return water;
}


//小数部分如果余数出现两次就表示该小数是循环小数了
string fractionToDecimal(int numerator, int denominator) {
    if(denominator==0) return "";//边界条件，分母为0
    if(numerator==0) return "0";//边界条件，分子为0
    string result;
    
    //转换为longlong防止溢出
    long long num = static_cast<long long>(numerator);
    long long denom = static_cast<long long>(denominator);
    
    //处理正负号，一正一负取负号
    if((num>0)^(denom>0))result.push_back('-');
    
    //分子分母全部转换为正数
    num=llabs(num);
    denom=llabs(denom);
    
    //处理整数部分
    result.append(to_string(num/denom));
    
    //处理小数部分
    num%=denom;                         //获得余数
    if(num==0)return result;             //余数为0，表示整除了，直接返回结果
    result.push_back('.');              //余数不为0，添加小数点
    int index = (int)(result.size() - 1);          //获得小数点的下标
    unordered_map<int,int> record;      //map用来记录出现重复数的下标，然后将'('插入到重复数前面就好了
    while(num&&record.count(num)==0){   //小数部分：余数不为0且余数还没有出现重复数字
        record[num]=++index;
        num*=10;                        //余数扩大10倍，然后求商，和草稿本上运算方法是一样的
        result+=to_string(num/denom);
        num%=denom;
    }
    if(record.count(num)==1){           //出现循环余数，我们直接在重复数字前面添加'(',字符串末尾添加')'
        result.insert(record[num],"(");
        result.push_back(')');
    }
    return result;
}
