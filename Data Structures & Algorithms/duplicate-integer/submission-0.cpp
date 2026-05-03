class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s= {};
        for (int num:nums){
            if (s.find(num)!=s.end()){
                return true;
            } else {
                s.insert(num);
            }

        }
        return false;
        
    }
};