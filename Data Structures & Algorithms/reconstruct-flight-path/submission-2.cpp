class Solution {
public:
    bool dfs( unordered_map<string,multiset<string>> & flights,vector<string> & ans, int target, string from ){
        ans.push_back(from);
        if (ans.size()==target) return true;
        for (auto it = flights[from].begin();it!=flights[from].end();it++){
            string nextto = *it;
            flights[from].erase(it);
            if (dfs(flights,ans,target,nextto)) return true;
            flights[from].insert(nextto);
        }
        ans.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> flights;
        vector<string> ans;
        int len = tickets.size()+1;
        for (auto v : tickets){
            flights[v[0]].insert(v[1]);
        }
        
        dfs(flights,ans,len,"JFK");
        return ans;

    }
};
