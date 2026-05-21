class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> allowed={{'}','{'},{']','['},{')','('}};
        vector<char> stac;
        for (char c:s){
            int n=stac.size()-1;
            if (!allowed.contains(c)){
                stac.push_back(c);
            } else {
                if (stac.size()>0) {
                    if (!(stac[n]==allowed[c])) return false;
                    else{  stac.pop_back(); }
                } else {
                    return false;
                }
            }
        }
        if (stac.size()>0) return false;
        return true;
    }
};
