class Solution {
    
public:
    unordered_map<int,int> d;
    int dp(span<char> s){
        if (d.contains(s.size())) return d[s.size()];
        if (s.size()==0) return 1;
        if (s[0]=='0') return 0;
        if (s.size()==1) return 1;
        int ans=0;
        int after1 =dp(s.subspan(1));
        int after2 = dp(s.subspan(2));
        if ((s[0]=='1'&&s[1]!='0')||(s[0]=='2'&&s[1]>'0'&&s[1]<'7')){
            ans+=after2+after1;
        }
        else if ((s[0]=='1'&&s[1]=='0')||(s[0]=='2'&&s[1]=='0')){
            ans+=after2;
        } //else if ((s[0]=='1'||s[0]=='2')&&(s[1]=='0'))
        else {ans+=after1;}
        d[s.size()]=ans;
        
        return ans;
        

        
    }
    int numDecodings(string s) {
        if (s.size()==0||s[0]=='0') return 0;
        span<char> sp(s);
        return dp(sp);
        
    }
};
