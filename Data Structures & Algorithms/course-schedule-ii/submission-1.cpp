class Solution {
    unordered_map<int, unordered_set<int>> preMap;
    unordered_set<int> visited;
    vector<int> ans;
    unordered_set<int> ansvals;
public:
    bool dfs(int course){
        if (visited.contains(course)) return false;
        
        if (!preMap.contains(course)) {if (!ansvals.contains(course)){ans.push_back(course);ansvals.insert(course);}return true;}
        visited.insert(course);
        for (int pre:preMap[course]){
            if (!dfs(pre)) return false;
            
        }
        preMap[course].clear();
        visited.erase(course);
        if (!ansvals.contains(course)){ans.push_back(course);ansvals.insert(course);}
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (!canFinish(numCourses, prerequisites)) return vector<int>();
        return ans;
    }
};
