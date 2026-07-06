class Solution {
public:
    unordered_map<int,int> buymemo;
    map<pair<int,int>,int> sellmemo;
    int sell(vector<int>& prices, int i, int price){
        if (i>=prices.size()) return 0;
        pair<int,int> key(i,price);
        if (sellmemo.contains(key)) return sellmemo[key];
        int waitLonger = sell(prices, i+1, price);              // hold, don't sell today
        int sellToday = (prices[i]-price) + buy(prices, i+2);   // sell today
        int best = max(waitLonger, sellToday);
        sellmemo[key] = best;
        return best;
        
    }
    int buy(vector<int>& prices, int i){
        if (i>=prices.size()) return 0;
        if (buymemo.contains(i)) return buymemo[i];
        int waitOneDay = buy(prices, i+1);              // skip buying today
        int buyToday = sell(prices, i+1, prices[i]);     // buy today, then decide when to sell
        return buymemo[i] = max(waitOneDay, buyToday);
    }
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int m=0;
        for (int i=0;i<prices.size();i++){
            m=max(m,buy(prices,i));
        }
        return m;

    }
};
