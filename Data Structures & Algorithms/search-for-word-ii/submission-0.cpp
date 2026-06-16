/*
class Solution {
public:
    bool checkup(vector<vector<char>>& board, int x, int y, char c){
        y -= 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkdown(vector<vector<char>>& board, int x, int y, char c){
        y += 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkleft(vector<vector<char>>& board, int x, int y, char c){
        x -= 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkright(vector<vector<char>>& board, int x, int y, char c){
        x += 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }

    bool recurse(vector<vector<char>>& board, span<char> word, int x, int y){
        int ytot = board.size();
        int xtot = board[0].size();
        
        // If we matched the previous letter and there are no letters left to match, we won!
        if (word.size() == 1) return true;
        
        // Grab the NEXT character we actually need to look for
        char next_char = word[1];
        
        // BACKTRACKING: Temporarily mark this cell as visited so neighbors can't reuse it
        char original_char = board[y][x];
        board[y][x] = '#'; 

        // 1. UP
        if (y > 0 && checkup(board, x, y, next_char)){
            y--;
            if (recurse(board, word.subspan(1), x, y)){ return true; } 
            y++;
        }
        // 2. DOWN (FIXED BOUNDARY)
        if (y < ytot - 1 && checkdown(board, x, y, next_char)){
            y++;
            if (recurse(board, word.subspan(1), x, y)){ return true; } 
            y--;
        }
        // 3. LEFT
        if (x > 0 && checkleft(board, x, y, next_char)){
            x--;
            if (recurse(board, word.subspan(1), x, y)){ return true; } 
            x++;
        }
        // 4. RIGHT (FIXED BOUNDARY)
        if (x < xtot - 1 && checkright(board, x, y, next_char)){
            x++;
            if (recurse(board, word.subspan(1), x, y)){ return true; } 
            x--;
        }

        // BACKTRACKING: Restore the character when returning up the tree
        board[y][x] = original_char;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ytot = board.size();
        int xtot = board[0].size();
        
        for (int x = 0; x < xtot; x++){
            for(int y = 0; y < ytot; y++){
                if (board[y][x] == word[0]) {
                    if (recurse(board, span<char>(word), x, y)) return true;
                } 
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool checkup(vector<vector<char>>& board, int x, int y, char c){
        y -= 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkdown(vector<vector<char>>& board, int x, int y, char c){
        y += 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkleft(vector<vector<char>>& board, int x, int y, char c){
        x -= 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool checkright(vector<vector<char>>& board, int x, int y, char c){
        x += 1;
        if (board[y][x] == c){ return true; } 
        else { return false; }
    }
    bool recurse(vector<vector<char>>& board, span<char> word, int x, int y){
        int ytot = board.size();
        int xtot = board[0].size();
        
        // If we matched the previous letter and there are no letters left to match, we won!
        if (word.size() == 1) return true;
        
        // Grab the NEXT character we actually need to look for
        char next_char = word[1];
        
        // BACKTRACKING: Temporarily mark this cell as visited so neighbors can't reuse it
        char original_char = board[y][x];
        board[y][x] = '#'; 
        bool flag=false;
        // 1. UP
        if (y > 0 && checkup(board, x, y, next_char)){
            y--;
            if (recurse(board, word.subspan(1), x, y)){ flag=true; } 
            y++;
        }
        // 2. DOWN (FIXED BOUNDARY)
        if (y < ytot - 1 && checkdown(board, x, y, next_char)){
            y++;
            if (recurse(board, word.subspan(1), x, y)){ flag=true; } 
            y--;
        }
        // 3. LEFT
        if (x > 0 && checkleft(board, x, y, next_char)){
            x--;
            if (recurse(board, word.subspan(1), x, y)){flag=true; } 
            x++;
        }
        // 4. RIGHT (FIXED BOUNDARY)
        if (x < xtot - 1 && checkright(board, x, y, next_char)){
            x++;
            if (recurse(board, word.subspan(1), x, y)){ flag=true; } 
            x--;
        }

        // BACKTRACKING: Restore the character when returning up the tree
        board[y][x] = original_char;
        
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ytot = board.size();
        int xtot = board[0].size();
        
        for (int x = 0; x < xtot; x++){
            for(int y = 0; y < ytot; y++){
                if (board[y][x] == word[0]) {
                    if (recurse(board, span<char>(word), x, y)) return true;
                } 
            }
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (string word:words){
            if (exist(board,word)) ans.push_back(word);
        }
        return ans;
    }
};
