#include <stack>
using namespace std;
class CQueue {
    stack<int> stk1;
    stack<int> stk2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        int ret = -1;
        while (stk1.size() > 1)
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        if (!stk1.empty())
        {
            ret = stk1.top();
            stk1.pop();
        }
        // 再装回去
        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */