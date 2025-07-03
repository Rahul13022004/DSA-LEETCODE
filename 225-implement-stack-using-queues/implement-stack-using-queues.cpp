class MyStack {
public:
   queue<int>qu1;
   queue<int>qu2;
    MyStack() {
        
    }
    
    void push(int x) {
        qu1.push(x);    
    }
    
    int pop() {
        while(qu1.size()>1){
            qu2.push(qu1.front());
            qu1.pop();
        }
        int temp=qu1.front();
        qu1.pop();
        swap(qu1,qu2);
        return temp;
    }
    
    int top() {
        while(qu1.size()>1){
            qu2.push(qu1.front());
            qu1.pop();
        }
        int temp=qu1.front();
        qu2.push(qu1.front());
        qu1.pop();
        swap(qu1,qu2);
        return temp;

    }
    
    bool empty() {
        return qu1.empty();
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