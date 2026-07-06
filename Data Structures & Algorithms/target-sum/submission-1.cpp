class Solution {
public:
    map<pair<int,int>,int> memo;
    int dp(vector<int>& nums, int cur, int target, int index){
        pair<int,int> key (cur,index);
        if (memo.contains(key)) return memo[key];
        int ans = 0;
        if (cur==target && index==nums.size()) ans = 1;
        if (index>nums.size()-1) return ans;
        //ADD
        cur+=nums[index];
        ans+=dp(nums,cur,target,index+1);
        cur-=2*nums[index];
        ans+=dp(nums,cur,target,index+1);
        memo[key]=ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums,0,target,0);
    }
};
