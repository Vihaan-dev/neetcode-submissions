class Solution {
public:
    int dp(vector<int>& nums, int cur, int target, int index){
        int ans = 0;
        if (cur==target && index==nums.size()) ans = 1;
        if (index>nums.size()-1) return ans;
        //ADD
        cur+=nums[index];
        ans+=dp(nums,cur,target,index+1);
        cur-=2*nums[index];
        ans+=dp(nums,cur,target,index+1);
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums,0,target,0);
    }
};
