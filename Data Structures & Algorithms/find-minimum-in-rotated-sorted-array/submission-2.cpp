class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;int r=nums.size()-1;
        while (nums[l]>nums[r] && r-l>1){
            int m = (l+r)/2;
            if (nums[m]>nums[r]){
                l=m+1;
            } else {
                r=m;
            }

        }
        return min(nums[l],nums[r]);
    }
};
