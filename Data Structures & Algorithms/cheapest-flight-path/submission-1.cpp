class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;//price, count, dest
        for (auto flight: flights){
            graph[flight[0]].push_back(pair<int,int>(flight[2],flight[1]));
        }
        for (auto & [from,tolist]:graph){
            cout << from<<": ";
            for (auto to:tolist) cout << "(Dist:"<<to.first<<" Target:"<<to.second<<") ";
            cout <<endl;
            
        }
        pq.push(vector<int>({0,0,src}));
        while (!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if (cur[2]==dst && cur[1]<=k+1) return cur[0];
            for (auto next: graph[cur[2]]){
                pq.push(vector<int>({cur[0]+next.first,cur[1]+1,next.second}));
            }
        }
        return -1;

    }
};
