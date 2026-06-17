class Solution {
public:
    void bfs(vector<vector<int>>& grid,pair<int,int> cords,set<pair<int,int>>& visited,int& count){
        int row = cords.second;
        int col = cords.first;
        count ++;
        visited.insert(pair<int,int>(col,row));
        set<pair<int,int>> neighbors;
        if (row>0) neighbors.insert(pair<int,int>(col,row-1));
        if (col>0)neighbors.insert(pair<int,int>(col-1,row));
        if (row<grid.size()-1) neighbors.insert(pair<int,int>(col,row+1));
        if (col<grid[0].size()-1) neighbors.insert(pair<int,int>(col+1,row));
        for (auto el:neighbors){
            if (!visited.contains(el)&&grid[el.second][el.first]==1){
                
                bfs(grid,el,visited,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<pair<int,int>> visited;
        int count=0;
        int m=0;
        for (int row = 0;row<grid.size();row++){
            for (int col = 0;col<grid[0].size();col++){
                if (visited.contains(pair<int,int>(col,row))) continue;
                else {
                    if (grid[row][col]==0) {
                        visited.insert(pair<int,int>(col,row));
                        continue;
                    } else {
                        count = 0;
                        bfs(grid,pair<int,int>(col,row),visited,count);
                        m=max(m,count);
                    }

                }
            }
        }
        return m;
    }
};
