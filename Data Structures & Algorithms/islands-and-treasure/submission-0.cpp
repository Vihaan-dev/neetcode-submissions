class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> & tovisit,int & count,set<pair<int,int>> & visited){
        int xtot=grid[0].size()-1;
        int ytot=grid.size()-1;
        int s= tovisit.size();
        for (int i=0;i<s;i++){
            auto cords = tovisit.front();
            tovisit.pop();
            int x = cords.first;
            int y = cords.second;
            grid[y][x] = min(grid[y][x],count);
            visited.insert(cords);
            if (x>0 && grid[y][x-1]!=-1 && !visited.contains(pair<int,int>(x-1,y))){
                tovisit.push(pair<int,int>(x-1,y));
            }
            if (y>0 && grid[y-1][x]!=-1 && !visited.contains(pair<int,int>(x,y-1))){
                tovisit.push(pair<int,int>(x,y-1));
            }
            if (x<xtot && grid[y][x+1]!=-1 && !visited.contains(pair<int,int>(x+1,y))){
                tovisit.push(pair<int,int>(x+1,y));
            }
            if (y<ytot && grid[y+1][x]!=-1 && !visited.contains(pair<int,int>(x,y+1))){
                tovisit.push(pair<int,int>(x,y+1));
            }
        }
        count++;
        if (tovisit.empty()) return;
        bfs(grid,tovisit,count,visited);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>  tovisit;
        int count=0;
        set<pair<int,int>> visited;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==0){
                    visited.clear();
                    count=0;
                    tovisit.push(pair<int,int>(j,i));
                    bfs(grid,tovisit,count,visited);
                }
            }
        }
    }
};
