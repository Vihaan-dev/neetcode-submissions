class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> counts;
        for (int num:nums){
            counts[num]+=1;
        }
        int count=0;
        for (int i=0;i<3;i++){
            for (int j =0;j<counts[i];j++){
                nums[count]=i;
                count++;
            }
        }
    }
};