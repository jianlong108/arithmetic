//
//  CircleDeque.hpp
//  算法 双向循环队列-数组实现
//
//  Created by Wangjianlong on 2021/1/17.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef CircleDeque_hpp
#define CircleDeque_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

template <class E>
class CircleDeque {
    E *m_elements;
    int m_size;
    int m_capacity;
    // 队头元素索引
    int front;
    int realIndex(int index);
public:
    CircleDeque() {
        cout << "Circle()" << endl;
        m_capacity = 10;
        m_elements = new E[m_capacity];
    }
    ~CircleDeque() {
        cout << "~Circle()" << endl;
    }
    bool isEmpty();
    void clear();
    void ensureCapacity(int capacity);
    void enQueue(E element);
    void enQueueFront(E element);
    E deQueue();
    E deQueueRear();
    E frontElement();
    string toString();
    string description();
};

template <class E>
bool CircleDeque<E>::isEmpty()
{
    return m_size == 0;
}

template <class E>
void CircleDeque<E>::clear()
{
    for (int i = 0; i<m_size; i++) {
        m_elements[i] = NULL;
    }
    m_size = 0;
    front = 0;
}

template <class E>
void CircleDeque<E>::ensureCapacity(int capacity) {
    int oldCapacity = m_capacity;
    if (oldCapacity >= capacity) return;
    
    // 新容量为旧容量的1.5倍
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    E *newElements = new E[newCapacity];
    for (int i = 0; i < m_size; i++) {
        newElements[i] = m_elements[(front + i)%m_capacity];
    }
    m_elements = newElements;
    m_capacity = newCapacity;
    // 重置front
    front = 0;
}

//容量为6
//m_size = 4 front = 2 next == 0 == (front + m_size) % m_capacity
//索引 |00 | 01 | 02 | 03 | 04 | 05 |
//元素 | 0 | 0  | e  | e  |  e |  e |

template <class E>
void CircleDeque<E>::enQueue(E element)
{
    ensureCapacity(m_size + 1);
    int nextIndex = (front + m_size) % m_capacity;
    m_elements[nextIndex] = element;
    m_size++;
}

template <class E>
void CircleDeque<E>::enQueueFront(E element)
{
    ensureCapacity(m_size + 1);
    int nextIndex = (front - 1 + m_capacity) % m_capacity;
    m_elements[nextIndex] = element;
    m_size++;
    front = nextIndex;
}

template <class E>
E CircleDeque<E>::deQueue()
{
    E ele = m_elements[front];
    m_elements[front] = NULL;
    m_size--;
    front = (front + 1) % m_capacity;
    return ele;
}

template <class E>
E CircleDeque<E>::deQueueRear()
{
    int tailIndex = (front + m_size) % m_capacity;
    E ele = m_elements[tailIndex];
    m_elements[tailIndex] = NULL;
    m_size--;
    return ele;
}

template <class E>
int CircleDeque<E>::realIndex(int index)
{
    front += index;
    if (front < 0) {
        return front + m_capacity;
    }
    return (front + m_capacity) % m_capacity;
}

template <class E>
E CircleDeque<E>::frontElement()
{
    return m_elements[front];
}

template <class E>
string CircleDeque<E>::toString()
{
    string s("长度为:");
    s+= to_string(m_size);
    s += "容量:";
    s += to_string(m_capacity);
    s += "front:";
    s += to_string(front);
    s+= "元素为:[";
    for (int i = 0; i<m_size; i++) {
        int index = (i+front) % m_capacity;
        int ele = m_elements[index];
        s+= to_string(ele);
        if (i != m_size - 1) {
            s+= ",";
        }
    }
    s+= "]";
    return s;
}

template <class E>
string CircleDeque<E>::description()
{
    string s("循环双端队列-");
    return s+= toString();
}

#endif /* CircleDeque_hpp */
