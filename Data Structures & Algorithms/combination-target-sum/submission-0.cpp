class Solution {
public:
    void recurse(vector<vector<int>>& ans,vector<int>& cur,span<int> nums, int s){
        if (s==0){
            ans.push_back(cur);
            return;
        } if (nums.size()==0) return;
        int m = nums[0];
        nums=nums.subspan(1);
        int c=0;
        while (s>=0){
            recurse(ans,cur,nums,s);
            cur.push_back(m);
            s-=m;
            c++;
        }
        for (int i=0;i<c;i++) cur.pop_back();

        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            vector<int> cur;
            sort(nums.begin(),nums.end());
            recurse(ans,cur,span<int>(nums),target);
            return ans;

            
    }
};
