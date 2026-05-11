class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for (int num:nums) counts[num]+=1;
        vector<vector<int>> l(nums.size()+1);
        for (auto & [key,val]:counts){
            l[val].push_back(key);
        }
        int count=0;
        vector<int> ans;
        for (int j=nums.size();count<k;j--){
            if (l[j].size()>0){
                for (int i=0;i<l[j].size();i++){
                    ans.push_back(l[j][i]);
                    count++;
                    if (count==k) break;
                }
            }
        }
        return ans;
    }
};
