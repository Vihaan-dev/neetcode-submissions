class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;int r=0;
        int m=INT_MAX;
        int s=nums[0];
        while (r<nums.size()){
            if (s>=target){
                m=min(m,r-l+1);
                if (l<r) {
                s-=nums[l];
                l++;
                } else r++;
            } else {
                
                r++;
                if (r>=nums.size()) break;
                s+=nums[r];
            }
            //cout <<l<<' '<<r<<' '<<s<<endl;
        }
        if (m==INT_MAX) return 0;
        return m;
    }
};