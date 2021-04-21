//
//  AboutStack.hpp
//  arithmetic
//
//  Created by JL on 2021/3/12.
//  Copyright © 2021 wangjianlong. All rights reserved.
//

#ifndef AboutStack_hpp
#define AboutStack_hpp

#include <stdio.h>


/*
 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 */
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            auto t = st.top();
            st.pop();
            res[t] = i - t;
        }
        st.push(i);
    }
    return res;
}


#endif /* AboutStack_hpp */
