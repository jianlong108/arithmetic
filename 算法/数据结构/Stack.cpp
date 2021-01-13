//
//  Stack.cpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/19.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "Stack.hpp"

/*
using namespace std;

Status pushStack(SqStack *stack, int value)
{
    //栈满
    if (stack->top == MAXSIZE - 1) {
        return Error;
    }
    //栈顶指针增加一
    stack->top ++;
    //将新元素赋值给栈顶空间
    stack->data[stack->top] = value;
    return OK;
}

Status popStack(SqStack *stack, int *value)
{
    if (stack->top == -1) {
        return Error;
    }
    *value = stack->data[stack->top];
    stack->top--;
    return OK;
}

Status push(SqDoubleStack *stack,int value,int stackNum)
{
    //栈满
    if (stack->top1 + 1 == stack->top2) {
        return Error;
    }
    
    if (stackNum == 1) {
        stack->top1++;
        stack->data[stack->top1] = value;
    }
    if (stackNum == 2) {
        stack->top2--;
        stack->data[stack->top2] = value;
    }
    return OK;
}

Status pop(SqDoubleStack *stack,int *value,int stackNum)
{
    if (stackNum == 1) {
        if (stack->top1 == -1) {
            return Error;
        }
        *value = stack->data[stack->top1];
        stack->top1--;
        return OK;
    }
    else if (stackNum == 2) {
        if (stack->top2 == MAXSIZE) {
            return Error;
        }
        *value = stack->data[stack->top2];
        stack->top1++;
        return OK;
    } else {
        return Error;
    }
}

//栈的链式存储结构，入栈操作
Status linkPush(LinkStack *stack,int value)
{
    LinkStackPtr top = stack->top;
    if (top == NULL) {
        return Error;
    }
    LinkStackPtr newP = (LinkStackPtr)malloc(sizeof(StackNode));
    newP->val = value;
    newP->next = top->next;
    top->next = newP;
    stack->count ++;
    return OK;
}

Status linkPop(LinkStack *stack,int *value)
{
    LinkStackPtr top = stack->top;
    if (top == NULL) {
        return Error;
    }
    *value = top->val;
    LinkStackPtr tmp = top->next;
    stack->top = tmp;
    free(top);
    stack->count --;
    return OK;
}


std::string getTmpString(std::string s)
{
    LinkStackOperator *stack = (LinkStackOperator *)malloc(sizeof(LinkStackOperator));
    stack->count = 0;
    
    string tmp = string("");
    size_t length = s.length();
    for (size_t i = 0; i<length; i++) {
        char c = s.at(i);
        if (c >= 48 && c<= 57) {//数字
            tmp += string(&c);
        } else if (c == '*' || c == '/' || c == '+' || c == '-' || c == ')') {
            
        }
    }
    return tmp;
}

bool vaildOperaterChar(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-' || c == ')') {
        return true;
    }
    return false;
}
*/
