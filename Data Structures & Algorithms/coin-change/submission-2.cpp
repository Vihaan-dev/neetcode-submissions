class Solution {
public:
    unordered_map<int,int> memo;
    int dp(vector<int>& coins, int amt){
        if (amt == 0) return 0;
        if (amt < 0) return INT_MAX;  // sentinel for "impossible"
        if (memo.contains(amt)) return memo[amt];
        int best = INT_MAX;
        for (int c : coins){
            int sub = dp(coins, amt - c);
            if (sub != INT_MAX) best = min(best, sub + 1);
        }
        return memo[amt] = best;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = dp(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};