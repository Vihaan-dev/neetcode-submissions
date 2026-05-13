class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0 ) return 0;
        int m=1;
        set<int> c(nums.begin(),nums.end());
        vector<int>s(c.begin(),c.end());
        int count=1;
        for (int i=0;i<s.size()-1;i++){
            if (s[i]+1==s[i+1]){
                count++;
            } else {count=1;}
            if (count>m) m=count;
        }
        return m;
    }
};
