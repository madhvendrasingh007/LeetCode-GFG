#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
    
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            transfer();
        }
        int topElement = out_stack.top();
        out_stack.pop();
        return topElement;
    }

    int peek() {
        if (out_stack.empty()) {
            transfer();
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};