class MinStack {
public:
    stack<pair<int,int>>s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int minEle=INT_MAX;
        if(s.empty())
        {
            minEle=val;
        }
        else
        {
            minEle=min(s.top().second,val);
        }
        s.push({val,minEle});
          
    }
    
    void pop() {
        if(s.empty())
            return;
        else
            s.pop();
        
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;    
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