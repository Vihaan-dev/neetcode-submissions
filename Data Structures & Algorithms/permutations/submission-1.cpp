class Solution {
    vector<vector<int>> ans;
public:
    void recurse(vector<int>& nums, int k ){
        if (nums.size()==k) ans.push_back(nums);
        for (int i=k;i<nums.size();i++){
            int temp = nums[i];
            nums[i]=nums[k];
            nums[k]=temp;
            recurse(nums,k+1);
            temp = nums[i];
            nums[i]=nums[k];
            nums[k]=temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        recurse(nums,0);
        return ans;
    }
};
