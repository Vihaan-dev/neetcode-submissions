class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_set<string>>> boxes(3,vector<unordered_set<string>>(3));
        vector<unordered_set<string>> rows(9);
        vector<unordered_set<string>> cols(9);
        
        for (int i=0;i<9 ;i++){
            for (int j=0;j<9 ;j++){
                string el=string(1,board[i][j]);
                if (el!="."){
                    if (rows[i].contains(el)){
                        return false;
                    } else rows[i].insert(el);
                    if (cols[j].contains(el)){
                        return false;
                    } else cols[j].insert(el);
                    
                    if (boxes[i/3][j/3].contains(el)){
                        return false;
                    } else boxes[i/3][j/3].insert(el);
                }
            }
        }
        return true;

    }
};
