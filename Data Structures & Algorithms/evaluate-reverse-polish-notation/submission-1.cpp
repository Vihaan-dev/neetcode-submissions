class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for (string t :tokens){
            if (t=="+"){
                int a = ops.top();
                ops.pop();
                int b=ops.top();
                ops.pop();
                ops.push(a+b);
            } else if (t=="/"){
                int a = ops.top();
                ops.pop();
                int b=ops.top();
                ops.pop();
                ops.push(b/a);
            } else if (t=="-"){
                int a = ops.top();
                ops.pop();
                int b=ops.top();
                ops.pop();
                ops.push(b-a);
            }else if (t=="*"){
                int a = ops.top();
                ops.pop();
                int b=ops.top();
                ops.pop();
                ops.push(a*b);
            } else {
                ops.push(stoi(t));
            }
        }
        return ops.top();
    }
};
