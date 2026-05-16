class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int k=0;k<nums.size()-3;k++){
            for (int i=k+1;i<nums.size()-2;i++){
                
                int l=i+1;int r=nums.size()-1;
                while (l<r){
                    long int s=1LL+nums[k]+nums[i]+nums[l]+nums[r];
                    s-=1;
                    //if (s>=INT_MAX) continue;
                    if (s==target){
                        ans.push_back({nums[k],nums[i],nums[l],nums[r]});
                        int prevl=nums[l];
                        while (l<nums.size()-1 && nums[l+1]==prevl && l<r) l++;
                        l++;

                    }
                    else {
                        if (s>target) r--;
                        else l++;
                    }
                }
                while (nums[i+1]==nums[i])i++;
            }
            while (nums[k+1]==nums[k])k++;
        }
        return ans;
    }
};