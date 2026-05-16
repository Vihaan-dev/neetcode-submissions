class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int curw=0;
        int m=0;
        vector<int> left;
        vector<int> right;
        for (int i=0;i<height.size();i++){
            if(height[i]>=m){
                //water+=curw;
                curw=0;
                m=height[i];
                left.push_back(0);
            } else {
                left.push_back(m-height[i]);
                curw+=m-height[i];
            }
        }
        for (int num:left) cout <<num<<' ';
        cout<<endl;
        m=0;
        curw=0;
        for (int i=height.size()-1;i>=0;i--){
            if(height[i]>=m){
                //water+=curw;
                curw=0;
                m=height[i];
                right.push_back(0);
            } else {
                right.push_back(m-height[i]);
                curw+=m-height[i];
            }
        }
        for (int num:right) cout <<num<<' ';
        cout<<endl;
        reverse(right.begin(),right.end());
        for (int i=0;i<height.size();i++){
            water+=min(left[i],right[i]);
        }
        return water;
    }
};
