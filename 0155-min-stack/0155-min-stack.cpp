class MinStack {
public:
stack<pair<int,int>>s1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty())
        {
            s1.push({val,val});
        }
        else{
            s1.push({val,min(val,s1.top().second)});
        }
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */