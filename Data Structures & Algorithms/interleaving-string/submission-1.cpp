class Solution {
public:
    map<vector<int>,bool> memo;
    bool dp(string s1, string s2, string s3, int i,int j,int k){
        vector<int> key = {i,j,k};
        if (memo.contains(key)) return memo[key];
        if (i==s1.size()&&j==s2.size()&&k==s3.size()){ memo[key]=true;return true;}
        if ((i==s1.size() || j==s2.size() )&& k==s3.size()){ memo[key]=false; return false;}
        if (s3[k]!=s1[i]&&s3[k]!=s2[j]) { memo[key]=false;return false;}
        if (s3[k]==s1[i]&&s3[k]==s2[j]) { bool val = (dp(s1,s2,s3,i+1,j,k+1)||dp(s1,s2,s3,i,j+1,k+1));memo[key]=val;return val;}
        if (s3[k]==s1[i]) { bool val = dp(s1,s2,s3,i+1,j,k+1);memo[key]=val;return val;}
        if (s3[k]==s2[j]) { bool val =dp(s1,s2,s3,i,j+1,k+1); memo[key]=val;return val;}
        return memo[key]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size()!=s1.size()+s2.size()) return false;
        return dp (s1,s2,s3,0,0,0);
    }
};
