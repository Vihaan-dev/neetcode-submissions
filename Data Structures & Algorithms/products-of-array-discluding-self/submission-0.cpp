class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_set<int> z; int p=1;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0) z.insert(i);
            else p*=nums[i];
        }
        int numz=z.size();
        vector<int> ans(nums.size(),p);
        for (int i=0;i<nums.size();i++){
            if (z.contains(i)){
                if (numz>1) ans[i]=0;
                else ans[i]=p;
            } else if (numz>0) {ans[i]=0;}
            else ans[i]=p/nums[i];
        }
        return ans;
    }       
};