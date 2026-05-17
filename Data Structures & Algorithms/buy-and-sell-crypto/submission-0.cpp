class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins=INT_MAX;
        
        int maxprof=0;
        for (int num:prices){
            mins = min(mins,num);

            int prof = num-mins;
            maxprof = max(prof,maxprof);
            //cout << num<<' '<<mins<<' '<<maxprof<<endl;
        }
        return maxprof;
    }
};
