class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref="";
        string c="";
        int i=-1;
        bool move=true;
        vector<int> lens={};
        int minLen=strs[0].size();
        for (string& s:strs){
            if (s.size()<minLen) minLen=s.size();
        }
        while (move){
            if (i>=0) pref+=c;
            i++;
            if (i<minLen){
                c = string(1,strs[0][i]);
                for (string str:strs){
                    if (string(1,str[i])!=c){
                        move=false;
                        break;
                    }
                }
            }else{
                move=false;
                break;
            }
        }
        return pref;
    }
};