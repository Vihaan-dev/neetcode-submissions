class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            span<int> slice =span(nums).subspan(i+1);
            auto pointer=find(slice.begin(),slice.end(),target-nums[i]);
            if (pointer==slice.end()) continue;
            else{
                int index = distance(slice.begin(),pointer);
                ans = {i,i+1+index};
                break;
            }


        }
        return ans;
    }
};
