#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long> s;
    long min;
    MinStack() {
        min = 0;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            min = val;
        }
        else if (min < val) {
            s.push(val);
        }
        else {
            s.push((long)val + val - min);
            min = val;

        }
    }

    void pop() {
        if (s.top() > min) {
            s.pop();
        } else {
            min = (long)2 * min - s.top();
            s.pop();
        }
    }

    int top() {
        if (s.top() > min) {
            return s.top();
        } else {
            return min;
        }
    }

    int getMin() {

        return min;

    }
};

int main() {

    MinStack* obj = new MinStack();
    int val = 2;
    obj->push(val);
    obj->pop();
    obj->push(val);
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}

/*

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

*/