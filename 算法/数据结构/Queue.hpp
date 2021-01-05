//
//  Queue.hpp
//  1-1链表
//
//  Created by wangjianlong on 2019/2/20.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Config.h"
//-------------------------------循环队列的顺序存储结构-----------------------
typedef struct {
    int data[MAXSIZE];
    /*头指针*/
    int front;
    /*尾指针,若队列不空，指向队列元素的下一个位置*/
    int rear;
} Queue;


/**
 初始化
 */
Status InitQueue(Queue *q);

int queueLength(Queue q);

Status pushQueue(Queue *q,int value);

//-------------------------------循环队列的链式存储结构-----------------------

//我们将队头指针指向链队列的头结点，而队尾指针指向终端结点

//结点结构
typedef struct QNode{
    int val;
    struct QNode *next;
} QNode,*QueuePtr;

//队列的链表结构
typedef struct {
    //队头，队尾指针。
    QueuePtr front,rear;
}LinkQueue;

Status entryQueue(LinkQueue *queue,int value);
Status deleteQueue(LinkQueue *queue,int value);
#endif /* Queue_hpp */
