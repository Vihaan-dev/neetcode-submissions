class Solution {
public:
    void dfs(unordered_map<int, vector<int>> & edges, int node, int prev, unordered_set<int> & vis){
        if (vis.contains(node))return;
        vis.insert(node);
        for (int next:edges[node]){
            if (next!=prev) dfs(edges, next,node, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> e;
        for (auto v: edges){
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        int count=0;
        unordered_set<int> vis;
        for (int i=0;i<n;i++){
            if (!vis.contains(i)){
                count ++;
                dfs(e, i,-1,vis);
            }
        }
        return count;
    }
};
