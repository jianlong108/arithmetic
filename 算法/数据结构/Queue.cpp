//
//  Queue.cpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/20.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "Queue.hpp"
#include <iostream>

Status InitQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    return OK;
}

int queueLength(Queue q)
{
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

Status pushQueue(Queue *q,int value)
{
    //队列满的判断
    if ((q->rear + 1)%MAXSIZE == q->front) {
        return Error;
    }
    //将元素赋给队尾元素
    q->data[q->rear] = value;
//    q->rear ++;
    q->rear = (q->rear + 1)%MAXSIZE;
    return OK;
}

Status popQueue(Queue *q,int *value)
{
    //队列空的判断
    if (q->rear == q->front) {
        return Error;
    }
    //将队头元素赋给value
    *value = q->data[q->front];
    //front 指针向后移一位
    //    q->front ++;
    q->front = (q->front + 1)%MAXSIZE;
    //若到最后，则转到数组头部
    return OK;
}

Status entryQueue(LinkQueue *queue,int value)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) {
        
        return Error;
    }
    
    p->val = value;
    p->next = NULL;
    //把拥有元素value新节点p赋值给原队尾结点的后继
    queue->rear->next = p;
    //把当前的p设置为队尾结点，rear指向p
    queue->rear = p;
    
    return OK;
}

Status deleteQueue(LinkQueue *queue,int *value)
{
    QueuePtr p;
    if (queue->front == queue->rear) {
        return Error;
    }
    p = queue->front->next;
    
    queue->front->next = p->next;
    *value = p->val;
    
    //若队头是队尾，则删除后将rear指向头结点
    if (queue->rear == p) {
        queue->rear = queue->front;
    }
    
    free(p);
    
    return OK;
}
