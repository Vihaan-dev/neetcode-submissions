class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;int r=heights.size()-1;
        int m=0;
        while (l<r){
            cout <<l<<' '<<r<<endl;
            m=max((r-l)*min(heights[r],heights[l]),m);
            if (heights[r]<heights[l])r--;
            else l++;
            
        }
        return m;
    }
};
