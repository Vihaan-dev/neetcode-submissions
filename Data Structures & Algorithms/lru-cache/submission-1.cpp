class LRUCache {
    unordered_map<int,int> kv;
    unordered_map<int,list<int>::iterator> its;
    list<int> order;
    int c;
    int count=0;

public:
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if (kv.contains(key)){
            updateTime(key);
            return kv[key];
        } else return -1;
    }
    
    void put(int key, int value) {
        if (kv.contains(key)){
            
        } else {
            if (c==kv.size()){
                int k=order.front();
                order.pop_front();
                its.erase(k);
                kv.erase(k);
            }
        }
        kv[key]=value;
        updateTime(key);
        
        
    }
    void updateTime(int key){
        if (its.contains(key)){
            order.erase(its[key]);
        } 
        order.push_back(key);
        its[key]=--order.end();
        
    }
};
