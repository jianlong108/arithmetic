//
//  List.hpp
//  算法
//
//  Created by JL on 2021/1/12.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#include <iostream>

template <class T>
class List {
public:
    static const int ELEMENT_NOT_FOUND = -1;
    /**
     * 清除所有元素
     */
    virtual void clear();

    /**
     * 元素的数量
     */
    virtual int size();

    /**
     * 是否为空
     */
    virtual bool isEmpty();

    /**
     * 是否包含某个元素
     */
    virtual bool contains(T element);

    /**
     * 添加元素到尾部
     */
    virtual void add(T element);

    /**
     * 获取index位置的元素
     */
    virtual T get(int index);

    /**
     * 设置index位置的元素
     * @return 原来的元素ֵ
     */
    virtual T set(int index, T element);

    /**
     * 在index位置插入一个元素
     */
    virtual void add(int index, T element);

    /**
     * 删除index位置的元素
     */
    virtual T remove(int index);

    /**
     * 查看元素的索引
     */
    virtual int indexOf(T element);
};
