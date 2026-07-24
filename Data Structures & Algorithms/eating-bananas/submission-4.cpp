class Solution {
public:
    int evalh(vector<int>& piles,int k){
        int h=0;
        for (int p:piles){
            int tobeadded=(p+k-1)/k;
            h+=tobeadded;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxk=*max_element(piles.begin(), piles.end());
        int mink=1;
        int midk = (maxk +mink)/2;
        int midh = evalh(piles,midk);
        while (true){
            if (maxk==mink) return mink;
            if (midh>h){
                mink=midk+1;
            } else {
                maxk = midk;
            }
            
            midk = (mink+maxk)/2;
            midh = evalh(piles,midk);
        }
        return midk;
        

        
    }
};
