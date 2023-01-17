class MinStack {
    vector<int> m_stk;
    vector<int> m_minstk;
public:
    MinStack() {

    }
    
    void push(int val) {
        m_stk.push_back(val);
        if (m_minstk.empty() || val <= m_minstk.back()) {
            m_minstk.push_back(val);
        }
    }
    
    void pop() {
        if (m_stk.back() == m_minstk.back()) {
            m_minstk.pop_back();
        }
        m_stk.pop_back();
    }
    
    int top() {
        return m_stk.back();
    }
    
    int getMin() {
        return m_minstk.back();
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
