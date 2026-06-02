class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast =0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (nums[slow]!=nums[fast]){
            slow = nums[slow];
            fast = nums[nums[fast]]; 
        }
        int slow2=0;
        while (nums[slow]!=nums[slow2]){
            slow = nums[slow];
            slow2 = nums[slow2]; 
        }
        return nums[slow]; 
    }
};
