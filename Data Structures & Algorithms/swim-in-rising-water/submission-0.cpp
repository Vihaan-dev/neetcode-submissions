class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;//{num,x,y}
        map<vector<int>,vector<vector<int>>> edges;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                vector<int> key = {grid[i][j],i,j};
                if (i>0){
                    edges[key].push_back(vector<int>({grid[i-1][j],i-1,j}));
                }
                if (j>0){
                    edges[key].push_back(vector<int>({grid[i][j-1],i,j-1}));
                }
                if (i<grid.size()-1){
                    edges[key].push_back(vector<int>({grid[i+1][j],i+1,j}));
                }
                if (j<grid[0].size()-1){
                    edges[key].push_back(vector<int>({grid[i][j+1],i,j+1}));
                }
            }
            
        }
        int m = grid[0][0];
        pq.push(vector<int>({m,0,0}));
        set<vector<int>> visited;
        while (!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            visited.insert(cur);
            m=max(cur[0],m);
            if (cur[1]==grid.size()-1&&cur[2]==grid[0].size()-1) return m;
            for (auto v:edges[cur]){
                if (!visited.contains(v))
                pq.push (v);
            }
        }
        return m;

    }
}; 
