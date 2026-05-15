class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1=0;
        int i2=0;
        string ans="";
        while (i1<word1.size() && i2<word2.size()){
            ans+=word1[i1];
            ans+=word2[i2];
            i1++;
            i2++;
        }
        while (i1<word1.size()){
            ans+=word1[i1];
            i1++;
        }
        while (i2<word2.size()){
            ans+=word2[i2];
            i2++;
        }
        return ans;
    }
};