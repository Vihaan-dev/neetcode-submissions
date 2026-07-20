class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size()<2 || k>=s.size()) return s.size();
        unordered_map<char,int> counts;
        int i=0;
        int j=0;
        int m=0;
        int curTot=0;
        int curMax=0;
        while (j<s.size()){
            
            char lc=s[j];
            
           
            counts[lc]++;
            curMax=max(curMax,counts[lc]);
            if (j-i+1-curMax<=k){
                
                
            } else {
                while (j-i+1-curMax>k){
                    counts[s[i]]--;
                    i++;
                    
                }

            }
            m=max(j-i+1,m);
            j++;
        }
        return m;
    }
};
