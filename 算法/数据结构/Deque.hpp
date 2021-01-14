//
//  Deque.hpp
//  算法
//
//  Created by JL on 2021/1/14.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef Deque_hpp
#define Deque_hpp

#include <stdio.h>
#include "LinkList.hpp"

template <class E>
class Deque {
    LinkList<E> *m_list;
    
public:
    Deque() {
        m_list = new LinkList<E>();
    }
    int size() {
        return m_list->size();
    }

    bool isEmpty() {
        return m_list->isEmpty();
    }
    
    void clear() {
        m_list->clear();
    }

    void enQueueRear(E element) {
        m_list->add(element);
    }

    E deQueueFront() {
        return m_list->remove(0);
    }

    void enQueueFront(E element) {
        m_list->addAtIndex(0, element);
    }

    E deQueueRear() {
        return m_list->remove(m_list->size() - 1);
    }

    E front() {
        return m_list->get(0);
    }

    E rear() {
        return m_list->get(m_list->size() - 1);
    }
    string description() {
        return "双向队列" + m_list->toString();
    }
};

#endif /* Deque_hpp */
