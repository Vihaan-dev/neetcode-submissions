class Solution {
public:
    vector<vector<int>> memo;
    int dp(int m,int n){
        if (memo[m][n]!=-1) return memo[m][n];
        if (m==1 && n==2 || m==2 && n==1 || m==1 && n==1) return 1;

        int ans = 0;
        if (m>1) ans += dp(m-1,n);
        if (n>1) ans += dp(m,n-1);
        return memo[m][n]=ans;
    }
    int uniquePaths(int m, int n) {
        memo.assign(m+1,vector<int>(n+1,-1));
        return dp(m,n);
        
    }
};
