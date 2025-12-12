class MinStack {
    private:
     stack<long long> s;
        long long mini;
public:
    MinStack() {
      while(!s.empty())
      s.pop();
      mini = LLONG_MAX;

    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini=val;
        }
        else{
            if(val<mini){
             
             s.push(2LL*val-mini);
             mini=val;
            }
            else{
                s.push(val);
            }
        }
    }
    
   void pop() {
       
        if(s.empty()){
        return;
        }
        long long curr=s.top();
        s.pop();
        if(curr<mini){
           mini=2LL*mini-curr;
        }
        
        
    }
    
    int top() {
        
        if(s.empty()){
           return -1; 
        }
        long long curr=s.top();
        if(curr<mini){
            return (int)mini;
        }
        else{
            return (int)curr;
        }
        
    }
    
    int getMin() {
        if(s.empty())
        return -1;

        return (int)mini;
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