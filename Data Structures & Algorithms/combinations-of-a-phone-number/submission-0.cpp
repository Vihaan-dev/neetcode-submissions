class Solution {
    unordered_map<char, vector<char>> letters = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
public:
    void recurse(vector<string>& ans, string & cur,span<char> inp){
        if (inp.size()==0&&cur!=""){
            ans.push_back(cur);
        }
        char dig = inp[0];
        for (int i=0;i<letters[dig].size();i++){
            cur+=letters[dig][i];
            recurse(ans,cur,inp.subspan(1));
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        recurse(ans,s,span<char>(digits));
        return ans;

    }
};
