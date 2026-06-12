class Solution {
    unordered_map<int,int> counts;
    vector<vector<int>> ans;
public:
    void recurse( vector<int>& cur, span<int> l){
        if (l.size()==0){
            ans.push_back(cur);
            return;
        }
        int el = l[0];
        l=l.subspan(1);
        int c=0;
        while (c<=counts[el]){
            recurse(cur,l);
            cur.push_back(el);
            c++;
        }
        
        for (int i=0;i<c;i++) cur.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int i:nums) counts[i]++;
        vector<int> uniquenums;
        vector<int> cur;
        for (auto & [k,v]:counts){
            uniquenums.push_back(k);
        }
        recurse(cur, span<int>(uniquenums));
        return ans;
    }
};
