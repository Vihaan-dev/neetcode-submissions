class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> n(nums.begin(),nums.end());
        int ans=1;
        while (true){
            if (n.contains(ans)) ans++;
            else return ans;
        }
    }
};