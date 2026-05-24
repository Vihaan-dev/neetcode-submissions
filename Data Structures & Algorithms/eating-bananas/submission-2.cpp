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
        
        //int s=0;
        //for (int p:piles)s+=p;
        int maxk=*max_element(piles.begin(), piles.end());
        int mink=1;
        
        int maxh=evalh(piles,mink);
        int minh=piles.size();
        while (true){
            if (maxk-mink<2){break;}
            int midk=(mink+maxk)/2;
            int midh=evalh(piles,midk);
            if (midh>h){
                mink=midk;
                maxh=midh;
            } 
             else {
                maxk=midk;
                minh=midh;
            } 
        }
        if (evalh(piles,mink)<=h) return mink;
        else return maxk;

        
    }
};
