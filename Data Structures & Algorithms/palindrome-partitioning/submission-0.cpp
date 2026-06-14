class Solution {
public:
    vector<vector<string>> ans;
    bool pal(span<char> s){
        int l=0;
        int r = s.size()-1;
        while (l<=r){
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void recurse(span<char> word, vector<string>& cur){
        if (word.size()==0) {
            ans.push_back(cur);
        }
        for (int i=1;i<=word.size();i++){
            if (pal(word.first(i))){
                cur.emplace_back(word.first(i).begin(),word.first(i).end());
                recurse(word.subspan(i),cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        recurse(span<char>(s),cur);
        
        return ans;
    }
};
