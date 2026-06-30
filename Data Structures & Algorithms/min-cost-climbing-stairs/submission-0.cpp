class Solution{
    unordered_map<int,int> dict;
public:
    int recurse(vector<int>& cost, int i){
        
        if (dict.contains(i)) return dict[i];
        if (i>=cost.size()) return 0;
        int res =cost[i] +min(recurse(cost,i+1),recurse(cost,i+2));
        dict[i]=res;
        return res;

    }
    int minCostClimbingStairs(vector<int>& cost) {
        //dict[cost.size()-1]=0;
        return min(recurse(cost,0),recurse(cost,1));
    }
};
