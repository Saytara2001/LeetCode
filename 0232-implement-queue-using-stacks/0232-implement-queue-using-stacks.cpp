class MyQueue {
public:
    int top;
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty()) top = x;
        st.push(x);
    }
    
    int pop() {
        stack<int> tmp;
        while(st.size()) {
            tmp.push(st.top());
            st.pop();
        }
        int popped = tmp.top();
        if(tmp.size()) tmp.pop();
        if(tmp.size()) top = tmp.top();
        while(tmp.size()) {
            st.push(tmp.top());
            tmp.pop();
        }
        return popped;
     }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */