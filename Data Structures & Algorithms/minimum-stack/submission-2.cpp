class MinStack {
public:
    stack<int> st, mnst;
    int mn = INT_MAX;
    MinStack() {
        st = {};
        mnst = {};
    }
    
    void push(int val) {
        st.push(val);
        if(val<=mn)
        {
            mnst.push(val);
            mn=val;
        }
    }
    
    void pop() {
        int tp = st.top();
        st.pop();
        if(mnst.top()==tp)
        {
            mnst.pop();
            mn = mnst.empty() ? INT_MAX : mnst.top();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnst.top();
    }
};
