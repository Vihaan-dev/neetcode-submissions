class MedianFinder {
    multiset<int> s;
    multiset<int>::iterator mid;
    bool inc = false;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
        if (s.size()==1) mid = s.begin();
        if (*mid>num) mid=prev(mid,1);
        if (inc){
            mid = next(mid,1);
        }
        inc=!inc;
    }
    
    double findMedian() {
        if (s.size()%2){
            return *mid;
        } else {
            return ((double)(*mid + *prev(mid,1))/2);
        }
    }
};
