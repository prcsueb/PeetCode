class MyQueue {
    Stack<Integer> in;
    Stack<Integer> out;
    public MyQueue() {
        in = new Stack<>();
        out = new Stack<>();
    }
    
    public void push(int x) {
        in.push(x);
    }
    
    public void transfterInToOut() {
        while(!in.isEmpty()) {
            int x = in.pop();
            out.push(x);
        }
    }
    
    public int pop() {
        int x = 0;
        if(empty()) return 0;
        else {
            if(!out.isEmpty()) {
                x = out.pop();
                return x;
            } else if(!in.isEmpty() && out.isEmpty()) {
                transfterInToOut();
                x = out.pop();
            }
        }
        return x;
    }
    
    public int peek() {
        if(empty()) {
            return 0;
        } else {
            int x = 0;
            if(!out.isEmpty()) {
                x = out.peek();
                return x;
            }
            else if(!in.isEmpty() && out.isEmpty()) {
                transfterInToOut();
                x = out.peek();
                return x;
            }
        }
        return 0;
    }
    
    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */