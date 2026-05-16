class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-2;i++){
            
            int l=i+1;int r=nums.size()-1;
            while (l<r){
                int s=nums[i]+nums[l]+nums[r];
                if (s==0){
                     ans.push_back({nums[i],nums[l],nums[r]});
                     int prevl=nums[l];
                     while (l<nums.size()-1 && nums[l+1]==prevl && l<r) l++;
                     l++;

                }
                else {
                    if (s>0) r--;
                    else l++;
                }
            }
            while (nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};
