class Solution {
public:
    bool validPalindrome(string s) {
        int count=0;
        int r=s.size()-1;
        cout << r<<endl;
        int l=0;
        while (l<r && count <2){
            if (!isalnum(s[l])){
                l++;
                continue;
            }
            if (!isalnum(s[r])){
                r--;
                continue;
            }
            if (tolower(s[l])!=tolower(s[r])){
                cout << l<<' '<<r<<endl;
                cout << (s[l])<<' '<<(s[r])<<endl;
                if (count==1) return false;
                count ++;
                if (s[l+1]==s[r] && s[l]==s[r-1]){
                    if (s[l+2]==s[r-1]) l++;
                    else if (s[r-2]==s[l+1])r--;
                }
                else if (s[l+1]==s[r]) l++;
                else if (s[l]==s[r-1]) r--;
                else return false;
            }
            l++;r--;

        }
        return true;
    
    }
};