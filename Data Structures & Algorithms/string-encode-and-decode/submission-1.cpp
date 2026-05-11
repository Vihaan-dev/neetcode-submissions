class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (string s:strs){
            ans+=s+";&;";
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i=0;
        int j=0;
        vector<string> ans;
        while (i<s.size()&&j<s.size()-2){
            if (s.substr(j,3)==";&;"){
                ans.push_back(s.substr(i,j-i));
                i=j+3;
                j=i;
            } else {j++;}
        }
        return ans;
    }
};
