class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> ans;
        int target=nums.size()/3;
        unordered_map<int,int> counts;
        for (int num:nums){
            counts[num]++;
            if (counts[num]>target) ans.insert(num);
        }
        vector<int> ans1(ans.begin(),ans.end());
        return ans1;
    }
};