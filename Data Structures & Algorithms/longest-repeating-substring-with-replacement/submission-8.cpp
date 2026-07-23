class Solution{
public:
    bool isValid (string&s, int i, int j, int k,unordered_map<char,int>& counts){
        int maxc=0;
        for (auto & [k,v]:counts){
            maxc = max(maxc,v);
        }
        return j-i+1-maxc<=k;

    }
    int characterReplacement(string s, int k) {
        if (s.size()<2 || k>=s.size()) return s.size();
        unordered_map<char,int> counts;
        int i=0;
        int j=0;
        int m=0;
        while (j<s.size()){
            counts[s[j]]++;
            while (!isValid(s,i,j,k, counts)){
                counts[s[i]]--;
                i++;
            }
            m=max(m,j-i+1);
            j++;
        }
        return m;
    }
};
