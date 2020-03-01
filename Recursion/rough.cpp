class MinStack {
public:
    stack<signed long int> st;
    signed long int MinSf = 0;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(signed long int val){
        if (st.size() == 0)
        {
            st.push(val);
            MinSf = val;
            return;
        }

        if (MinSf < val)
            st.push(val);
        else
        {
            st.push(2 * val - MinSf);
            MinSf = val;
        }
        
    }
    
    void pop() {

        if (st.size() == 0)
            cout<<-1;

        if (st.top() < MinSf)
        {
            signed long int j = st.top();
            st.pop();
            signed long int actualValue = MinSf;

            signed long int recoveredMinSf = 2 * MinSf - j;

            MinSf = recoveredMinSf;
            cout<<actualValue;
        }
        else
        {
            signed long int j = st.top();
            st.pop();
            cout<<j;
        }
        
    }
    
    signed long int top() {
        if (st.size() == 0)
            return -1;

        if (st.top() < MinSf)
            return MinSf;
        else
            return st.top();
        
    }
    
    signed long int getMin() {
        if (st.size() == 0)
            return -1;
        return MinSf;
    }
        
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */