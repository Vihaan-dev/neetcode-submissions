class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> ans(s.begin(),s.end());
        for (int i=0;i<ans.size();i++){
            nums[i]=ans[i];
        }
        return ans.size();
    }
};