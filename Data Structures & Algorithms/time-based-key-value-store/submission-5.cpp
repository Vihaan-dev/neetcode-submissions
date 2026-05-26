class TimeMap {
    unordered_map<string,pair<unordered_map<int,string>,set<int>>> m;
    // {key:({1:w,2:k},2)}
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        m[key].first[timestamp]=value;
        m[key].second.insert(timestamp);
        
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].second.upper_bound(timestamp);
        if (it==m[key].second.begin()) return "";
        --it;
        
        
        return m[key].first[*it];
    }
};
