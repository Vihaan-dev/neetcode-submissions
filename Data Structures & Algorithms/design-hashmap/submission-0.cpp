class MyHashMap {
    vector<bool> keys;
    vector<int> vals;
public:
    MyHashMap() : keys(1e6+1,false),vals(1e6+1){
        
    }
    
    void put(int key, int value) {
        keys[key]=true;
        vals[key]=value;
    }
    
    int get(int key) {
        if (keys[key] ) return vals[key];
        else return -1;
    }
    
    void remove(int key) {
        keys[key]=false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */