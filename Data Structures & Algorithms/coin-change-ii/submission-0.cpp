class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& coins,int rem,int i){
        if (memo[rem][i]!=-1) return memo[rem][i];
        if (rem==0) return 1;
        if (i>=coins.size())return 0;
        int s = 0;
        for (int j = 0;j<=rem/coins[i];j++){
            s+=dp(coins,rem-coins[i]*j,i+1);
        }
        memo[rem][i]=s;
        return s;
    }
    int change(int amount, vector<int>& coins) {
        memo.assign(5001,vector<int>(101,-1));
        return dp(coins,amount,0);
    }
};
