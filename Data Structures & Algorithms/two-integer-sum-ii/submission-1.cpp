class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i=0;i<numbers.size();i++){
            for (int j=i;j<numbers.size();j++){
                if (numbers[j]==target-numbers[i]) {
                    vector<int> ans={i+1,j+1};
                    return ans;
                }  ;
            }
        }
    }
};
