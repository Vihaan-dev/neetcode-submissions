class Solution {
public:
    vector<int> merge(vector<int> a,vector<int> b){
        vector<int> merged;
        int i=0;
        int j=0;
        for (; i<a.size() && j<b.size();){
            if (a[i]>=b[j]){
                merged.push_back(b[j]);
                j++;
            } else {
                merged.push_back(a[i]);
                i++;
            }

        }
        merged.insert(merged.end(),a.begin()+i,a.end());
        merged.insert(merged.end(),b.begin()+j,b.end());
        
        return merged;
    }
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size()==1) return nums;
        int mid=nums.size()/2;
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid,nums.end());
        return merge(sortArray(left),sortArray(right));

    }
};