//
//  Stack.hpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/19.
//  Copyright © 2019 JL.Com. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <iostream>
#include "Config.h"
#include "ArrayList.hpp"

using namespace std;

template <class T>
class Stack {
    ArrayList <T> *m_list;
public:
    Stack(){
        m_list = new ArrayList<T>(2);
    }
    void clear() {
        m_list->clear();
    }
    
    int size() {
        return m_list->length();
    }

    bool isEmpty() {
        return m_list->isEmpty();
    }

    void push(T element) {
        m_list->add(element);
    }

    T pop() {
        return m_list->remove(m_list->length() - 1);
    }

    T top() {
        return m_list->get(m_list->length() - 1);
    }
    
    string toString() {
        return m_list->toString();
    }
};


/*
//-------------------------------栈的顺序存储结构-----------------------
//定义栈

typedef struct {
    int data[MAXSIZE];
    int top;//用作栈顶指针
} SqStack;

Status pushStack(SqStack *stack, int value);
Status popStack(SqStack *stack, int *value);


//两栈共享空间
 
 数组有两个端点，两个栈有两个栈底，让一个栈的栈底为数组的开始端，即index = 0。让另一个栈的栈底为数组的末端。即index = n-1;这样，如果两个栈增加元素，就是两端点向中间延伸。
 
 两个栈，在数组的两端，向中间靠拢。top1和top2是栈1和栈2的栈顶指针，可以想象，只要他们不见面，两个栈就可以一直使用。
 
 栈1为空时，top1 = -1; 栈2为空时，top2 = n;
 栈满： top1 = -1 top2 = 0； top1 = n-1;  top2 = n; top1 + 1 = top2;
//

typedef struct {
    int data[MAXSIZE];
    int top1;//用作栈顶指针
    int top2;//用作栈顶指针
} SqDoubleStack;

Status push(SqDoubleStack *stack,int value,int stackNum);
Status pop(SqDoubleStack *stack,int *value,int stackNum);

//-------------------------------栈的链式存储结构-----------------------

typedef struct StackNode
{
    int val;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status linkPush(LinkStack *stack,int value);

//用栈实现简单的四则运算 9+（3-1）*3+10/2

typedef struct OperatorNode
{
    char operatorChar;
    struct StackNode *next;
}OperatorNode, *LinkOperatorPtr;

typedef struct LinkStackOperator
{
    LinkStackPtr top;
    int count;
}LinkStackOperator;

std::string getTmpString(std::string s);
*/
