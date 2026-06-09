class Solution {
public:
    struct ComparePairs {
        bool operator()(vector<int>& a,vector<int>& b) const {
        return (pow(a[0],2)+pow(a[1],2)<pow(b[0],2)+pow(b[1],2));
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,ComparePairs> q;
        for (auto el:points){
            q.push(el);
            if (q.size()>k) q.pop();

        }
        vector<vector<int>> ans;
        for (int i=0;i<k;i++){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
