class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        map<int,vector<int>> counts;
        for (int c:arr){
            counts[abs(c-x)].push_back(c);
        }
        int c=0;
        
        auto p=counts.begin();
        while (c<k){
            for (int num:p->second){
                ans.push_back(num);
                c++;
                if (c==k)break;
            }
            advance(p,1);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};