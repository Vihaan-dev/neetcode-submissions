class Solution {
public:
    int access(vector<int>& nums, int i,int mini){
        return nums[(mini+i)%nums.size()];
    }
    int search(vector<int>& nums, int target) {
        int l=0;int r=nums.size()-1;
        int mini=0;;
        while (nums[l]>nums[r] && r-l>1){
            int m= (l+r)/2;
            
            if (nums[m]>nums[r]){
                l=m;
            } else {
                r=m;
            }
        }
        if (nums[l]>nums[r]) mini=r;
        else mini=l;
        cout <<"MINI"<<mini<<endl;
        l=0;r=nums.size()-1;
        while (r-l>1){
            cout <<l<<' '<<r<<endl;
            int m=(l+r)/2;
            int mel=access(nums,m,mini);
            cout <<"M accessed"<<mel<<endl;
            if (mel==target) return (mini+m)%nums.size();
            else if (mel>target) r=m;
            else l=m;
            
        }
        if (access(nums,l,mini)==target) return (mini+l)%nums.size();
        else if (access(nums,r,mini)==target) return (mini+r)%nums.size();
        else return -1;
            
    }
};
