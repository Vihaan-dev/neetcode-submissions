class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s=nums.size();
        for (int num:nums){
            int counts=count(nums.begin(),nums.end(),num);
            if (counts>s/2) return num;
        }
    }
};