class MinStack {
    vector<int> stk;
    vector<int> min_stk;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push_back(val);
        if (min_stk.empty() || val <= min_stk.back()) {
            min_stk.push_back(val);
        }
    }
    
    void pop() {
        if (stk.back() == min_stk.back()) {
            min_stk.pop_back();
        }
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_stk.back();
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
