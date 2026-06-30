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
        if (nums.size()==1) return nums[0];
        int last = nums[nums.size()-1];
        nums.pop_back();
        int res1 = dp(nums,0);
        dict.clear();
        nums.push_back(last);
        int res2 = dp(nums,1);
        return max(res1,res2);
    }
};
