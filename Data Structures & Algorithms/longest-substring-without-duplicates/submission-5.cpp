class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<2) return s.size();
        int i=0;int j=0; int m=1;
        unordered_set<char> c={s[0]};
        while (j<s.size()-1){
            
            j++;
            while (c.contains(s[j])){
                c.erase(s[i]);
                i++;
            }
            c.insert(s[j]);
            m=max(j-i+1,m);
        }
        return m;
    }
};
