class KthLargest {
    priority_queue<int,vector<int>,greater<int>> q;
    int kval;
    
public:
    KthLargest(int k, vector<int>& nums) {
        kval=k;
        for (int el:nums){
            q.push(el);
            if (q.size()>kval) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size()>kval) q.pop();
        return q.top();
        
        
    }
};
