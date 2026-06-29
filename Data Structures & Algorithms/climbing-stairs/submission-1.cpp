class Solution {
    unordered_map<int,int> data={{1,1},{2,2}};
public:
    int climbStairs(int n) {
        if (data.contains(n)) return data[n];
        int res= (climbStairs(n-1)+climbStairs(n-2));
        data[n]=res;
        return res;
    }
};
