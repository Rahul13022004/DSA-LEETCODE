class MyStack {
public:
     queue<int>qu;
    MyStack() {
        
    }
    
    void push(int x) {
        qu.push(x);
        for(int i=0;i<qu.size()-1;i++){
           qu.push(qu.front());
           qu.pop();
        }
    }
    
    int pop() {
        int top=qu.front();
        qu.pop();
        return top;
    }
    
    int top() {
        int top= qu.front();
        return top;
    }
    
    bool empty() {
        return qu.empty();
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