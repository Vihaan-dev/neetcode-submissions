class Solution {
public:
    bool isAnagram(string s, string t) {
        set<char> sset(s.begin(),s.end());
        set<char> tset(t.begin(),t.end());
        if (counts(s)==counts(t)){
            return true;
        }
        return false;
    }
    unordered_map<char,int> counts(string s){
        unordered_map<char,int> dict;
        for (char c : s){
            if (dict.contains(c)){
                dict[c]+=1;
            }else{
                dict[c]=1;
            }
        }
        return dict;
    }
};
