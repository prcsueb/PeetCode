class MaxStack {
public:
    stack<int> dataStk, maxStk;
    MaxStack() {
        
    }
    
    void push(int x) {
        dataStk.push(x);
        if(!maxStk.empty()) {
            maxStk.push(max(maxStk.top(), x));
        } else {
            maxStk.push(x);
        }
    }
    
    int pop() {
        int top = dataStk.top();
        dataStk.pop();
        maxStk.pop();
        return top;
    }
    
    int top() {
        return dataStk.top();
    }
    
    int peekMax() {
        return maxStk.top();
    }
    
    int popMax() {
        stack<int> reserve;
        int tbr = maxStk.top();
        while(dataStk.top() != tbr) {
            reserve.push(pop());
        }
        pop();
        while(reserve.size() > 0) {
            int top = reserve.top();
            reserve.pop();
            push(top);
        }
        return tbr;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */