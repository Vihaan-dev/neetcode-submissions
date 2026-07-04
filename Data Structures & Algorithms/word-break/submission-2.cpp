class Solution {
    unordered_map<string,bool> memo;
public:
    bool dp(span<char> s, unordered_set<string>& wordDict){
        if (s.size()==0) return true;
        string tot = string(s.begin(),s.end());
        if (memo.contains(tot)) return memo[tot];
        for (int i=1;i<=s.size();i++){
            
            span<char> n = s.subspan(0,i);
            string str = string(n.begin(),n.end());
            //cout <<str<<endl;
            if (wordDict.contains(str)){
                //cout << "INIF";
                if (dp(s.subspan(i),wordDict)) {memo[tot]=true;return true;}
            }

        }
        memo[tot]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return dp(span<char>(s),dict);
    }
};
