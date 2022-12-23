class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_map<string, function<int(int, int)>> ops{
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }},
        };
        for (auto& token : tokens) {
            if (ops.find(token) == ops.end()) {
                stk.push(stoi(token));
            } else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                stk.push(ops[token](op1, op2));
            }
        }
        return stk.top();
    }
};
