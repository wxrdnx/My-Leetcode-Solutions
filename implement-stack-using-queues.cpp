class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int qsize = q.size();
        q.push(x);
        while (qsize--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int result = top();
        q.pop();
        return result;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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

// push: O(n)
// pop: O(1)
