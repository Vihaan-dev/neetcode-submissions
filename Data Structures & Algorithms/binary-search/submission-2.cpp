class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;int r=nums.size()-1;
        while (l<=r){
            if (r-l<2){
                if (nums[l]==target) return l;
                else if (nums[r]==target) return r;
                else break;
            }
            int t=(l+r)/2;
            if (nums[t]==target) return t;
            else if (target>nums[t]) l=t;
            else r=t;
        }
        return -1;
    }
};
