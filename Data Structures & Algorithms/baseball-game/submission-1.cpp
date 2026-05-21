class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for (string c:operations){
            if (isdigit(c[c.size()-1])){
                ans.push_back(stoi(c));
            }
            else if (c[0]=='+'){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }
            else if (c[0]=='D'){
                ans.push_back(ans[ans.size()-1]*2);
            } else if (c[0]=='C'){
                ans.pop_back();
            }
        }
        int s=0;
        for (int n:ans) s+=n;
        return s;
    }
};