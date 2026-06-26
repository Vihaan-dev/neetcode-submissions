class Solution {
public:
    int dist(vector<int> & point1,vector<int> & point2){
        return (abs(point1[0]-point2[0])+ abs(point1[1]-point2[1]));
    }
    void enqueue(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &pq,unordered_map<int, vector<pair<int,int>>> & edges,unordered_set<int>& visited, int node){
        //if (visited.contains(node)) return;
        for (auto edge:edges[node]){
            if (!visited.contains(edge.second)) pq.push(edge);
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<int>> id;
        unordered_map<int, vector<pair<int,int>>> edges; // {point:[{dist,point}]}
        unordered_set<int> visited;
        for (int i=0;i<points.size();i++){
            id[i]=points[i];
        }
        for (int i=0;i<points.size();i++){
            for (int j=i+1;j<points.size();j++){
                int d=dist(points[i],points[j]);
                edges[i].push_back(pair<int,int>(d,j));
                edges[j].push_back(pair<int,int>(d,i));
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,0));
        int c=0;
        while (!pq.empty()){
            pair<int,int> toadd = pq.top();
            pq.pop();
            while (visited.contains(toadd.second)){
                toadd=pq.top();
                pq.pop();
            }
            visited.insert(toadd.second);
            c+=toadd.first;
            enqueue(pq,edges, visited,toadd.second);
            cout << c<<endl;
            if (visited.size()==points.size()) return c;
        }
        return 0;
    }
};
