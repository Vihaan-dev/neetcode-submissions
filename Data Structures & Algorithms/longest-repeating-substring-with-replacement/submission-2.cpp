class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size()<2 || k>=s.size()) return s.size();
        int m=0;
        vector<vector<int>> count; // [[char,count,aux,storing],[...]]
        vector<vector<int>> countr;
        for (int i=0;i<s.size();i++){
            for (int j=0;j<i;j++){
                if (count[j][0]==s[i]-'A' && count[j][2]<=k && count[j][3]){
                    count[j][1] ++;
                } else if (count[j][0]!=s[i]-'A' && count[j][2]<k && count[j][3]){
                    count[j][1] ++;
                    count[j][2] ++;
                } else {count[j][3]=0;continue;}
                if (count[j][1]>m) m=count[j][1];
            }
            count.push_back({s[i]-'A',1,0,1});
        }
        for (int i=s.size()-1;i>=0;i--){
            for (int j=s.size()-1;j>i;j--){
                if (count[j][0]==s[i]-'A' && count[j][2]<=k && count[j][3]){
                    count[j][1] ++;
                } else if (count[j][0]!=s[i]-'A' && count[j][2]<k && count[j][3]){
                    count[j][1] ++;
                    count[j][2] ++;
                } else {count[j][3]=0;continue;}
                if (count[j][1]>m) m=count[j][1];
            }
            count.push_back({s[i]-'A',1,0,1});
        }
        return m;
    }
};
