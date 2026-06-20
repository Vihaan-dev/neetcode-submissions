class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> & tovisit, int & count, set<pair<int,int>> & visited){
        int xtot = grid[0].size() - 1;
        int ytot = grid.size() - 1;
        int s = tovisit.size();
        bool flag = false;
        
        for (int i = 0; i < s; i++){
            auto cords = tovisit.front();
            tovisit.pop();
            int x = cords.first;
            int y = cords.second;
            grid[y][x] = 2;
            
            // --- FIX 1: Removed visited.insert(cords) from here ---
            
            if (x > 0 && grid[y][x-1] == 1 && !visited.contains(pair<int,int>(x-1,y))){
                tovisit.push(pair<int,int>(x-1,y));
                visited.insert(pair<int,int>(x-1,y)); // FIX 2: Lock it down immediately
                flag = true;
            }
            if (y > 0 && grid[y-1][x] == 1 && !visited.contains(pair<int,int>(x,y-1))){
                tovisit.push(pair<int,int>(x,y-1));
                visited.insert(pair<int,int>(x,y-1)); // FIX 2: Lock it down immediately
                flag = true;
            }
            if (x < xtot && grid[y][x+1] == 1 && !visited.contains(pair<int,int>(x+1,y))){
                tovisit.push(pair<int,int>(x+1,y));
                visited.insert(pair<int,int>(x+1,y)); // FIX 2: Lock it down immediately
                flag = true;
            }
            if (y < ytot && grid[y+1][x] == 1 && !visited.contains(pair<int,int>(x,y+1))){
                tovisit.push(pair<int,int>(x,y+1));
                visited.insert(pair<int,int>(x,y+1)); // FIX 2: Lock it down immediately
                flag = true;
            }
        }
        
        if (flag) count++;
        if (tovisit.empty()) return;
        
        bfs(grid, tovisit, count, visited);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> tovisit;
        int count = 0;
        set<pair<int,int>> visited;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    tovisit.push(pair<int,int>(j,i));
                    visited.insert(pair<int,int>(j,i)); // FIX 3: Also mark initial rotten ones as visited
                }
            }
        }
        
        bfs(grid, tovisit, count, visited);
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};