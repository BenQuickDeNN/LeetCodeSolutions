#include <cstdlib>
#include <climits>
#include <stack>

class MinStack {
    std::stack<int> stk_data; // 数据栈
    std::stack<int> stk_min; // 最小栈

public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stk_data.push(x);
        if (stk_min.empty() || x <= stk_min.top())
            stk_min.push(x);
    }
    
    void pop() {
        if (stk_min.top() == stk_data.top())
            stk_min.pop();
        stk_data.pop();
    }
    
    int top() {
        return stk_data.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};

class BasicStack {
    int* data;
    int length;
public:
    /** initialize your data structure here. */
    BasicStack() {
        /* 分配内存 */
        data = (int*)std::malloc(sizeof(int));
        length = 0;
    }
    ~BasicStack()
    {
        std::free(data);
    }
    
    void push(int x) {
        /* 动态分配内存 */
        length++;
        data = (int*)std::realloc(data, (length + 1) * sizeof(int));
        data[length] = x;
    }
    
    void pop() {
        /* 动态分配内存 */
        length--;
        data = (int*)std::realloc(data, (length + 1) * sizeof(int));
    }
    
    int top() {
        return data[length];
    }
    
    int getMin() {
        int minVal = INT_MAX;
        for (int i = 1; i <= length; i++)
            if (minVal > data[i])
                minVal = data[i];
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */