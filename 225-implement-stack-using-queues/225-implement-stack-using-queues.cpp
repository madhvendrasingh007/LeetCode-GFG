class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int temp;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        temp=x;
    }
    
    int pop() {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        temp = q1.front();
        
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return (q1.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */