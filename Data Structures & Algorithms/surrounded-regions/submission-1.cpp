class Solution {
public:
    int key (int row, int col){
        return row*200+col;
    }
    vector<int> cords(int el){
        int col =el%200;
        int row = el/200;
        return vector<int>({row,col});
    }
    void dfs(vector<vector<char>>& board, int row, int col, unordered_set<int>& visited,bool & overall){
        visited.insert(key(row,col));
        cout <<row<<' '<<col<<endl;
        int lastrow = board.size()-1;
        int lastcol = board[0].size()-1;
        //BASE CASE
        if (board[row][col]=='O' && (row==0||row==lastrow||col==0||col==lastcol)){
            overall=false;
            return;
        }
        //Base case 2
        bool flag = true;
        if (row>0 && board[row-1][col]!='X'&&!visited.contains(key(row-1,col))) flag=false;
        if (row<lastrow && board[row+1][col]!='X'&&!visited.contains(key(row+1,col)))flag=false;
        if (col>0 && board[row][col-1]!='X'&& !visited.contains(key(row,col-1))) flag=false;
        if (col <lastcol && board[row][col+1]!='X'&&!visited.contains(key(row,col+1))) flag=false;
        if (flag&&overall){
            
            return;
        }
        if (row>0 && board[row-1][col]=='O' && !visited.contains(key(row-1,col))) {
            dfs(board,row-1,col,visited,overall);
        }
        if (row<lastrow && board[row+1][col]=='O' && !visited.contains(key(row+1,col))) {
            dfs(board,row+1,col,visited,overall);
        }
        if (col>0 && board[row][col-1]=='O' && !visited.contains(key(row,col-1))) {
            dfs(board,row,col-1,visited,overall);
        }
        if (col <lastcol && board[row][col+1]=='O' && !visited.contains(key(row,col+1))) {
            dfs(board,row,col+1,visited,overall);
        }
        

    }
    void solve(vector<vector<char>>& board) {
        int lastrow = board.size()-1;
        int lastcol = board[0].size()-1;
        for (int row = 1;row<lastrow;row++){
            for (int col = 1; col<lastcol;col++){
                if (board[row][col]=='O'){
                    unordered_set<int> visited;
                    bool overall = true;
                    dfs(board,row,col,visited,overall);
                    if (overall){
                        for (int el : visited){
                            vector<int> c = cords(el);
                            board[c[0]][c[1]]='X';
                        }
                    }
                    cout <<"END"<<endl;
                }
            }
        }
    }
};
