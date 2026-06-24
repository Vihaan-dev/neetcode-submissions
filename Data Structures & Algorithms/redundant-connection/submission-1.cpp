class Solution {
public:
    vector<int> dfs(vector<vector<int>>& edges, unordered_map<int,vector<int>> & edgemap, unordered_set<int>& visitedset,vector<int>& visited,int node, int prev){
        visited.push_back(node);
        visitedset.insert(node);
        for (int next:edgemap[node]){
            if (next==prev) continue;
            else if (visitedset.contains(next)){
                for (int i=edges.size()-1;i>=0;i--){
                    auto v = edges[i];
                    int v1i=-1;
                    int v0i=-1;
                    int nexti=0;
                    for (int j=0;j<visited.size();j++){
                        if (visited[j]==v[0]) v0i=j;
                        if (visited[j]==v[1]) v1i=j;
                        if (visited[j]==next) nexti=j;
                    }
                    if (v0i>=nexti && v1i>=nexti) return v;
                }
            }
            else {
                auto v= dfs(edges,edgemap,visitedset,visited,next,node);
                if (v.size()==2) return v;
            }
        }
        visited.pop_back();
        visitedset.erase(node);
        return vector<int>();
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> edgemap;
        vector<int> visited;
        unordered_set<int> visitedset;
        for (auto v:edges){
            edgemap[v[0]].push_back(v[1]);
            edgemap[v[1]].push_back(v[0]);
        }
        return dfs(edges,edgemap,visitedset,visited,1,0);
    }
};
