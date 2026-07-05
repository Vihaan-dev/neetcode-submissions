class Solution {
public:
    bool traverse(vector<int>& nums, int sum, int index){
        sum-=nums[index];
        if (sum==0) return true;
        for (int i=index+1;i<nums.size();i++){
            if (traverse(nums,sum,i)) return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int n:nums){
            sum+=n;
        }
        if (sum%2!=0)return false;
        sum/=2;
        if (traverse(nums,sum,0)) return true;
        if (traverse(nums,sum,1)) return true;
        return false;

    }
};
