class Solution {
public:
    string longestPalindrome(string s) {
        //span<char> w(s);
        int l=0;
        int r=0;
        int c=0;
        string ans = string(1,s[0]);
        while (c<s.size()){
            l=c;
            r=c;
            while (s[l]==s[r]){
                if (r-l+1>ans.size()){
                    ans=s.substr(l,r-l+1);
                }
                if (l>0 && r<s.size()-1 && s[l-1]==s[r+1]){
                    l--;
                    r++;
                }else break;
                
            }
            l=c;
            r=c+1;
            if (r==s.size())break;
            while (s[l]==s[r]){
                if (r-l+1>ans.size()){
                    ans=s.substr(l,r-l+1);
                }
                if (l>0 && r<s.size()-1 && s[l-1]==s[r+1]){
                    l--;
                    r++;
                } else break;
                
            }
            c++;
        }
        return ans;
    }
};
