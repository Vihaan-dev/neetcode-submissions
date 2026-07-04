class Solution {
    unordered_map<int,int> memo;
public:
    int dfs (vector<int> & nums, int index){
        if (memo.contains(index)) return memo[index];
        int val = nums[index];
        int m = 1;
        for (int i=index+1;i<nums.size();i++){
            if (nums[i]>val){
                m=max(m,1+dfs(nums,i));
            }
        }
        memo[index]=m;
        return m;

    }
    int lengthOfLIS(vector<int>& nums) {
        int m=0;
        for (int i=0;i<nums.size();i++){
            m=max(dfs(nums,i),m);
        }
        return m;
    }
};
