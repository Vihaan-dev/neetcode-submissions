class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        prefix[0]=1;
        int curSum=0;
        int count=0;
        for (int num:nums){
            curSum+=num;
            if (prefix.contains(curSum-k)){
                count+=prefix[curSum-k];

            }
            prefix[curSum]+=1;
        }
    return count;
    }
};