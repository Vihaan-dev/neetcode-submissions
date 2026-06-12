class Solution {
    vector<vector<int>> ans;
public:
    void recurse(vector<int>& cur, vector<int> left){
        if (left.size()==0) ans.push_back(cur);
        for (int i=0;i<left.size();i++){
            cur.push_back(left[i]);
            vector<int> newleft(left.begin(),left.begin()+i);
            newleft.insert(newleft.end(),left.begin()+i+1,left.end());
            recurse(cur,newleft);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        recurse(cur,nums);
        return ans;
    }
};
