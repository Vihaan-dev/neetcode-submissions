class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> counts;
        unordered_set<char> tset(t.begin(),t.end());
        unordered_map<char,int> countsb;
        vector<int>m={INT_MAX,0,0};
        for (char c:t){
            counts[c]++;
        }
        int req=tset.size();
        int filled=0;

        int l=0;int r=0;
        while (r<s.size()){
            cout<<l<<' '<<r<<endl;
            if (tset.contains(s[r])){
                countsb[s[r]]++;
                if (countsb[s[r]]==counts[s[r]]) filled++;
            }
            while (filled==req && l<=r){
                if (r-l+1<m[0]) m={r-l+1,l,r};
                if (tset.contains(s[l])) { 
                    countsb[s[l]]--;
                    if (countsb[s[l]]<counts[s[l]]) filled--;
                    //if (countsb[s[l]]==0) countsb.erase(s[l]);
                }
                l++;
            }
            
            cout<<m[0]<<' '<<m[1]<<' '<<m[2]<<endl;
            r++;

        }
        if (m[0]==INT_MAX) return "";
        string ans(s.begin()+m[1],s.begin()+m[2]+1);
        return ans;
    }
};
