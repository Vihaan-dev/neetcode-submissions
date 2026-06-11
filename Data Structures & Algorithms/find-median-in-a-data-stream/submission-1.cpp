class MedianFinder {
    multiset<int> s;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        if (s.size()%2){
            return *(next(s.begin(),(s.size())/2));
        } else {
            return ((double)(*(next(s.begin(),s.size()/2))+*(next(s.begin(),s.size()/2-1)))/2);
        }
    }
};
