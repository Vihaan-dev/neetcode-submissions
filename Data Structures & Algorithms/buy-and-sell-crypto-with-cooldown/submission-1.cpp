class Solution {
public:
    unordered_map<int,int> buymemo;
    map<pair<int,int>,int> sellmemo;
    int sell(vector<int>& prices, int i, int price){
        pair<int,int> key(i,price);
        if (sellmemo.contains(key)) return sellmemo[key];
        if (i>=prices.size()) return 0;
        int curProf = prices[i]-price;
        curProf += buy(prices,i+2);
        for (int j=i+1;j<prices.size();j++){
            curProf = max(sell(prices,j,price),curProf);
        }
        //memo curProf
        sellmemo[key]=curProf;
        return curProf;
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
