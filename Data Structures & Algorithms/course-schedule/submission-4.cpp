class Solution {
    unordered_map<int, unordered_set<int>> preMap;
    unordered_set<int> visited;
public:
    bool dfs(int course){
        if (visited.contains(course)) return false;
        
        if (!preMap.contains(course)) {return true;}
        visited.insert(course);
        for (int pre:preMap[course]){
            if (!dfs(pre)) return false;
            
        }
        preMap[course].clear();
        visited.erase(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (auto & v:prerequisites){
            preMap[v[0]].insert(v[1]);
        }
        
        for (int i=0;i<numCourses;i++){
            if (!dfs(i)) return false;

        }
        return true;

    }
};
