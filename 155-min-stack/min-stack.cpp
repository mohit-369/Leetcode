class MinStack {
vector<int> st,mi;
public:
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.size()==0)
        {
            st.push_back(val);
            mi.push_back(val);
        }

        else
        {
            int m = min(mi.back(),val);

            st.push_back(val);

            mi.push_back(m);
        }
        
    }
    
    void pop() {
        st.pop_back();
        mi.pop_back();
    }
    
    int top() {

       return st.back();
        
    }
    
    int getMin() {

       return mi.back();
        
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