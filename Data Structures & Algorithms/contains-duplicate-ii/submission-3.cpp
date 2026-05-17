class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> counts;

        for (int i=0;i<=k&&i<nums.size();i++){
            counts[nums[i]]++;
            if (counts[nums[i]]==2) return true;
        } 
        int i=0;
        for (int j=k;j<nums.size()-1;){
            counts[nums[i]]-=1;
            i++;
            j++;
            counts[nums[j]]+=1;
            if (counts[nums[j]]==2) return true;
        }
        return false;
        
    }
};