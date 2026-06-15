class Solution {
    
public:
    void addans(vector<vector<string>>& ans,vector<vector<unordered_set<char>>> & cur,int n){
        vector<string> tempans;
        for (int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                if (cur[i][j].contains('Q')) temp+='Q';
                else temp+='.';
            }
            tempans.push_back(temp);

        }
        ans.push_back(tempans);
    }
    void recurse(vector<vector<string>>& ans,vector<vector<unordered_set<char>>> & cur,int n,vector<unordered_set<char>> line){
        if (cur.size()==n) {addans(ans,cur,n);return;}
        vector<unordered_set<char>> newline(n);
        for (int i=0;i<n;i++){
            if (line[i].contains('b')) newline[i].insert('b');
            if (i<n-1&&line[i+1].contains('l')) newline[i].insert('l');
            if (i>0 && line[i-1].contains('r')) newline[i].insert('r');

        }
        for (int i=0;i<n;i++){
            if (line[i].empty()){
                line[i].insert('Q');
                cur.push_back(line);
                newline[i].insert('b');
                if (i>0) newline[i-1].insert('l');
                if (i<n-1) newline[i+1].insert('r');
                recurse(ans,cur,n,newline);
                line[i].erase('Q');
                newline[i].erase('b');
                if (i>0) newline[i-1].erase('l');
                if (i<n-1) newline[i+1].erase('r');
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<unordered_set<char>>>  cur;
        vector<unordered_set<char>> line(n);
        recurse(ans,cur,n,line);
        return ans;
    }
};
