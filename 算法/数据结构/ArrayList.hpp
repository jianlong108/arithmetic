//
//  ArrayList.hpp
//  算法
//
//  Created by JL on 2021/1/12.
//  Copyright © 2021 wangjianlong. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <iostream>
//#include "List.hpp"

using namespace std;

template <class T>
class ArrayList{
    int _size;
    int _capacity;
    T *_elements;
    const int DEFAULT_CAPACITY = 10;
    const int ELEMNT_NOT_FOUND = -1;
public:
    ArrayList(int capacity);
    void clear();
    int length();
    bool isEmpty();
    bool contains(T element);
    int indexOf(T element);
    void rangeCheck(int index);
    void rangeCheckForAdd(int index);
    void outOfBounds(int index);
    void add(T element);
    
    void addElementAtIndex(int index, T element);
    T remove(int index);
    T get(int index);
    /**
     * 设置index位置的元素
     * @return 原来的元素ֵ
     */
    T set(int index, T element);
    
    void ensureCapacity(int capacity);
    
    string toString();
};


template <class T>
ArrayList<T>::ArrayList(int capacity) {
    _capacity = (capacity < DEFAULT_CAPACITY)?DEFAULT_CAPACITY:capacity;
    _elements = new T[_capacity];
    _size = 0;
}

template <class T>
void ArrayList<T>::clear() {
    for (int i = 0; i < _size ; i++) {
        _elements[i] = NULL;
    }
    _size = 0;
}

template <class T>
int ArrayList<T>::length() {
    return _size;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return _size == 0;
}

template <class T>
bool ArrayList<T>::contains(T element) {
    return indexOf(element) != ELEMNT_NOT_FOUND;
}

template <class T>
int ArrayList<T>::indexOf(T element) {
    if (element == NULL) {  // 1
        for (int i = 0; i < _size; i++) {
            if (_elements[i] == NULL) return i;
        }
    } else {
        for (int i = 0; i < _size; i++) {
            //TODO 判断元素相等,这块需要优化
            if (_elements[i] == element) return i; // n
        }
    }
    return ELEMNT_NOT_FOUND;
}

template <class T>
void ArrayList<T>::rangeCheck(int index) {
    if (index < 0 || index >= _size) {
        outOfBounds(index);
    }
}

template <class T>
void ArrayList<T>::rangeCheckForAdd(int index) {
    if (index < 0 || index > _capacity) {
        outOfBounds(index);
    }
}

template <class T>
void ArrayList<T>::outOfBounds(int index) {
    throw string("outOfBoundsException:Index:") + to_string(index) + ", Size:" + to_string(_size);
}

template <class T>
void ArrayList<T>::add(T element) {
    addElementAtIndex(_size,element);
}

template <class T>
void ArrayList<T>::addElementAtIndex(int index, T element) {
    rangeCheckForAdd(index);
    ensureCapacity(_size + 1);
    for (int i = _size; i > index; i--) {
        _elements[i] = _elements[i - 1];
    }
    _elements[index] = element;
    _size++;
}

template <class T>
T ArrayList<T>::remove(int index) {
   rangeCheck(index);
   
   T old = _elements[index];
   for (int i = index + 1; i < _size; i++) {
       _elements[i - 1] = _elements[i];
   }
   _elements[--_size] = NULL;
   return old;
}

template <class T>
T ArrayList<T>::get(int index) {
    rangeCheck(index);
    return _elements[index];
}
/**
 * 设置index位置的元素
 * @return 原来的元素ֵ
 */
template <class T>
T ArrayList<T>::set(int index, T element) {
    rangeCheck(index);
    
    T old = _elements[index];
    _elements[index] = element;
    return old;
}

template <class T>
void ArrayList<T>::ensureCapacity(int capacity) {
    int oldCapacity = _capacity;
    if (oldCapacity >= capacity) return;
    
    // 新容量为旧容量的1.5倍
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    T *newElements = new T[newCapacity];
    for (int i = 0; i < _size; i++) {
        newElements[i] = _elements[i];
    }
    _capacity = newCapacity;
    _elements = newElements;
    
    std::cout << oldCapacity << "扩容为" << newCapacity << std::endl;
}

template <class T>
string ArrayList<T>::toString() {
    string s("元素:[");
    for (int i = 0; i < _size; i++) {
        string s1 = to_string(this->_elements[i]);
        s += s1;
        if (i != _size - 1) {
            s+=",";
        }
    }
    s+="]";
    return s;
}
