class MinStack {
public:
    stack<long long >st;
    int mn;
    MinStack() {
        mn=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mn=val;
            st.push(0);
        }else{
            st.push((long long)val-mn);
            if(val<mn){
                mn=val;
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()<0){
                mn=mn-st.top();
            }
            st.pop();
        }
        
    }
    
    int top() {
        if(!st.empty()){
            if(st.top()>0){
                return st.top()+mn;
            }else{
                return mn;
            }
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty()){
            return mn;
        }
        return -1;
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