class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>> cons; // {start:{[end,time]}}
        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});  // {dist, node} — min dist on top
        for (auto v: times){
            cons[v[0]].push_back(vector<int>({v[1],v[2]}));
        }
        while (!pq.empty()){
            auto newcon = pq.top();
            pq.pop();
            int node = newcon.second;
            int dist = newcon.first;
            if (visited.contains(node)) continue;
            visited.insert(node);
            for (auto v: cons[node]){
                /*if (!visited.contains(v[0]))*/pq.push({v[1]+dist,v[0]});
            }
            if (visited.size()==n) return dist;

        }
        
        return -1;


    }
};
