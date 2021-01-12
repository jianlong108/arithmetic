//
//  ArrayList.hpp
//  算法
//
//  Created by JL on 2021/1/12.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "List.hpp"

template <class T>
class ArrayList{
    int _size;
    int _capacity;
    T *_elements;
    const int DEFAULT_CAPACITY = 10;
    const int ELEMNT_NOT_FOUND = -1;
public:
    ArrayList(int capacity) {
        _capacity = (capacity < DEFAULT_CAPACITY)?DEFAULT_CAPACITY:capacity;
        _elements = new T[_capacity];
        _size = 0;
    }
    void clear() {
        for (int i = 0; i < _size ; i++) {
            _elements[i] = NULL;
        }
        _size = 0;
    }
    int length() {
        return _size;
    }
    bool isEmpty() {
        return _size == 0;
    }
    bool contains(T element) {
        return indexOf(element) != ELEMNT_NOT_FOUND;
    }
    int indexOf(T element) {
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
    void rangeCheck(int index) {
        if (index < 0 || index >= _size) {
            outOfBounds(index);
        }
    }
    void rangeCheckForAdd(int index) {
        if (index < 0 || index > _capacity) {
            outOfBounds(index);
        }
    }
    void outOfBounds(int index) {
        throw string("outOfBoundsException:Index:") + to_string(index) + ", Size:" + to_string(_size);
    }
    void add(T element) {
        addElementAtIndex(_size,element);
    }
    
    void addElementAtIndex(int index, T element) {
        rangeCheckForAdd(index);
        ensureCapacity(_size + 1);
        for (int i = _size; i > index; i--) {
            _elements[i] = _elements[i - 1];
        }
        _elements[index] = element;
        _size++;
    }
    T remove(int index) {
       rangeCheck(index);
       
       T old = _elements[index];
       for (int i = index + 1; i < _size; i++) {
           _elements[i - 1] = _elements[i];
       }
       _elements[--_size] = NULL;
       return old;
   }
    T get(int index) {
        rangeCheck(index);
        return _elements[index];
    }
    /**
     * 设置index位置的元素
     * @return 原来的元素ֵ
     */
    T set(int index, T element) {
        rangeCheck(index);
        
        T old = _elements[index];
        _elements[index] = element;
        return old;
    }
    
    void ensureCapacity(int capacity) {
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
    
    string toString() {
        string s("数组:[");
        for (int i = 0; i < _size; i++) {
            string s1 = std::to_string(this->_elements[i]);
            s += s1;
            if (i != _size - 1) {
                s+=",";
            }
        }
        s+="]";
        return s;
    }
};
