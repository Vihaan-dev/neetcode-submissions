class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int s=0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices[i+1] > prices[i]) {
                int amt=prices[i+1]-prices[i];
                if (amt>0) s+=amt;


            } 
        }
        return s;
        
    }
};