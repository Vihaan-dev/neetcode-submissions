class Solution {
public:
    // We pass 'parent' to prevent walking backward along the edge we just crossed
    bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int node, int parent) {
        visited.insert(node);
        
        for (int neighbor : adj[node]) {
            // TRICK A: Skip the back-edge to the parent. No erasing needed!
            if (neighbor == parent) continue;
            
            // TRICK B: If we hit a visited node that isn't our parent, it's a cycle!
            if (visited.contains(neighbor)) return false;
            
            // Recursively check the rest of the path
            if (!dfs(adj, visited, neighbor, node)) return false;
        }
        
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A classic tree math shortcut: an un-directed tree MUST have exactly n - 1 edges.
        // If it has more, there is a guaranteed cycle. If less, it's disconnected.
        if (edges.size() != n - 1) return false;

        // Build a standard adjacency list (using vector is faster than unordered_set here)
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        
        // Kick off DFS from node 0 exactly ONCE.
        // Node 0 has no parent, so we pass -1.
        if (!dfs(adj, visited, 0, -1)) {
            return false; // Found a cycle!
        }
        
        // If we processed all 'n' nodes from a single start, it's fully connected!
        return visited.size() == n;
    }
};