class MinStack {
public:
    long mn;
    stack<long> s;
    
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty())
        {
            mn=val;
            s.push(val);
        }
        else if(val>mn)
            s.push(val);
        else
        {
            s.push((long)2*val-mn);
            mn=val;
        }  
    }
    
    void pop() {
        if(s.top()<mn)
            mn=2*mn-s.top();
        
        s.pop();
    }
    
    int top() {
        if(s.top()>=mn)
        return s.top();
        
        return mn;
    }
    
    int getMin() {
        return mn;
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