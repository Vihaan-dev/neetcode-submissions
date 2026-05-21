class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<vector<int>> s;
        for (int i=0;i<temperatures.size();i++){
            if (s.size()==0) s.push({i,temperatures[i]});
            else {
                while (s.size()>0 && s.top()[1]<temperatures[i]){
                    ans[s.top()[0]]=i-s.top()[0];
                    s.pop();
                }
                s.push({i,temperatures[i]});
                
            }
        }
        return ans;
    }
};
