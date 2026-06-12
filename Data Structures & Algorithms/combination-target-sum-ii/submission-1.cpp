class Solution {
public:
    void recurse(unordered_map<int,int> &counts,vector<vector<int>>& ans,vector<int>& cur,span<int> nums, int s){
        if (s==0){
            ans.push_back(cur);
            return;
        } if (nums.size()==0) return;
        int m = nums[0];
        nums=nums.subspan(1);
        int c=0;
        while (s>=0&&c<=counts[m]){
            recurse(counts,ans,cur,nums,s);
            cur.push_back(m);
            s-=m;
            c++;
        }
        for (int i=0;i<c;i++) cur.pop_back();

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int,int> counts;
        for (int i :candidates) counts[i]++;
        
        vector<int> setonums;
        for (auto& [k,v]:counts) setonums.push_back(k);
        recurse(counts,ans,cur,span<int>(setonums),target);
        return ans;
    }
};
