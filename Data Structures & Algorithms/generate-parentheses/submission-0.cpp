class Solution {
    stack<char> ans;
    vector<string> l;
public:
    void textify(){
        string s(ans.size(),'\0');
        stack<char> temp;
        for (int i=s.size()-1;i>=0;i--){
            s[i]=ans.top();
            temp.push(ans.top());
            ans.pop();
        }
        l.push_back(s);
        while (!temp.empty()){
            ans.push(temp.top());
            temp.pop();
        }
        
    }
    void recurse(int open,int close){
        if (close==0&&open==0) {textify();return;}
        if (ans.empty()){
            ans.push('(');
            open--;
            recurse(open,close);
            ans.pop();
            open++;
        } else  {
            if (open>0){
                open--;
                ans.push('(');
                recurse(open,close);
                open++;
                ans.pop();
            }
            if (close>0 && open<close){
                close--;
                ans.push(')');
                recurse(open,close);
                ans.pop();
                close++;
            }
        }
        


        

    }
    vector<string> generateParenthesis(int n) {
        recurse (n,n);
        return l;
    }
};
