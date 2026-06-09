class KthLargest {
    set<int> s;
    unordered_map<int,int> counts;
    int kval;
public:
    KthLargest(int k, vector<int>& nums) {
        s.insert(nums.begin(),nums.end());
        kval=k;
        for (int el: nums){
            counts[el]++;
        }
    }
    
    int add(int val) {
        s.insert(val);
        counts[val]++;
        int c= 0;
        auto it = s.end();
        while (c<kval){
            it = prev(it);
            c+=counts[*it];

        }
        return *it;
    }
};
