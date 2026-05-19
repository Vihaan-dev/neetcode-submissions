class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> counts;
        
        int m=0;
        for (int i=0;i<k;i++){
            m=max(m,nums[i]);
            counts[nums[i]]++;
        }
        vector<int>ans={m};
        int i=0;
        int j=k-1;
        while (j<nums.size()-1){
            j++;
            counts[nums[j]]++;
            counts[nums[i]]--;
            
            if (counts[nums[i]]==0) counts.erase(nums[i]);
            i++;
            if (nums[j]>=m) m=nums[j];
            else {
                auto p=counts.end();
                advance(p,-1);
                m=p->first;
            }
            ans.push_back(m);
        }
        return ans;
    }
};
