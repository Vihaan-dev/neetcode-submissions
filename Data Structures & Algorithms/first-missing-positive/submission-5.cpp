class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            if (nums[i]<0){nums[i]=0;}
        }
        for (int i=0;i<nums.size();i++){
            if (abs(nums[i])-1>=0 && abs(nums[i])-1<nums.size()){
                if (nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]*=-1;
                else if (nums[abs(nums[i])-1]==0) nums[abs(nums[i])-1]=-1;
            }

        }
        int ans=1;
        while (ans<=nums.size()){
            if (nums[ans-1]<0) ans++;
            else return ans;
        }
        return ans;
    }
};