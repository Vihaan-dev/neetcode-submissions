class Solution {
public:
    bool dfs (unordered_map<int,unordered_set<int>> & edgemap,  unordered_set<int> &visited,unordered_set<int>& overall, int node ){
        if (visited.contains(node)) return false;
        visited.insert(node);
        overall.insert(node);
        for (auto next: edgemap[node]){
            edgemap[next].erase(node);
            if (!dfs(edgemap,visited,overall,next)){return false;}
        }
        visited.erase(node);
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,unordered_set<int>> edgemap;
        for (auto v: edges){
            edgemap[v[0]].insert(v[1]);
            edgemap[v[1]].insert(v[0]);
        }
        for (int i=0;i<n;i++){
            unordered_set<int> overall;
            unordered_set<int> visited;
            unordered_map<int,unordered_set<int>> edgemap1=edgemap;
            if (dfs(edgemap1, visited, overall,i)&&overall.size()==n){
                cout <<i<<endl;
                return true;
            }

        }
        return false;


    }
};
