class Solution {
    
public:
    void recurse(vector<vector<int>>& ans, vector<int> cur, span<int> l){
        if (l.size()==0){
            ans.push_back(cur);
            return;
        }
        int el = l[0];
        l=l.subspan(1);
        recurse(ans,cur,l);
        cur.push_back(el);
        recurse(ans,cur,l);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        recurse(ans,cur,span<int>(nums));
        return ans;


    }
};
