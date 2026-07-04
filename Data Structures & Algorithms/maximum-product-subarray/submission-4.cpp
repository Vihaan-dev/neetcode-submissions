class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = 1;
        int minProd = 1;
        
        int overall = INT_MIN;
        for (int i:nums){
            int prevMax = maxProd;
            int prevMin = minProd;
            maxProd = max({prevMax*i, prevMin*i, i});
            minProd = min({prevMax*i, prevMin*i, i});
            overall = max ({overall, maxProd});
            
        }
        return overall;

    }
};
