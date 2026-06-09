class Solution {
    priority_queue<int> q;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int stone:stones){
            q.push(stone);
        }
        while (q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if (y<x) q.push(x-y);
        }
        if (q.size()==0) return 0;
        return q.top();
    }
};
