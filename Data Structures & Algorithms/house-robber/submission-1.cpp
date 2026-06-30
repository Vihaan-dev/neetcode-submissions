class Solution {
    unordered_map<int,int> dict;
public:
    int dp(vector<int>& nums, int house){
        if (dict.contains(house)) return dict[house];
        if (house>=nums.size()) return 0;
        int res = max(nums[house]+dp(nums,house+2),dp(nums,house+1));
        dict[house] = res;
        return res;

    }
    int rob(vector<int>& nums) {
        return dp(nums,0);
    }
};
