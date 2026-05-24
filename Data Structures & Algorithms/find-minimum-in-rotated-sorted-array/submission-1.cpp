class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;int r=nums.size()-1;
        while (nums[l]>nums[r]&&r-l>=2){
            cout <<l<<' '<<r<<endl;
            int m=(l+r)/2;
            if (nums[m]>nums[r]){
                l=m;
            }else {
                r=m;
            }
        }
        return min(nums[r],nums[l]);
    }
};
