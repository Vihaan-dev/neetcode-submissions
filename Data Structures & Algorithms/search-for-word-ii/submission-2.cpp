class Node {
public:
    unordered_map<char,Node*> next;
    char c;
    bool end;
    string text;
    Node(char c, bool end):c(c),end(end){

    }
};

class WordDictionary {
public:
    Node* head;
    
    WordDictionary() {
        head = new Node('#',false);
    }
    
    void addWord(string word) {
        auto cur = head;
        for (int i = 0;i<word.size();i++){
            char c = word[i];
            if ((cur->next).contains(c)) cur = (cur->next)[c];
            else {
                auto newnode = new Node(c,false);
                (cur->next)[c]=newnode;
                cur = newnode;
            }
            if (i==word.size()-1) {(cur->end)=true;cur->text=word;}
        }
    }
    
};
class Solution {
public:
    
    void recurse(vector<vector<char>>& board, Node* cur, unordered_set<string> & ans,int x,int y){
        if (cur->end){ans.insert(cur->text);}
        if (cur->next.empty()) return;
        int xtot = board[0].size();
        int ytot = board.size();
        char ogchar = board[y][x];
        board[y][x]='#';
        //checkleft
        if (x>0){
            x--;
            char c = board[y][x];
            if ((cur->next).contains(c)){
                recurse(board,(cur->next)[c],ans,x,y);
            }
            x++;
        }
        //checkright
        if (x<xtot-1){
            x++;
            char c = board[y][x];
            if ((cur->next).contains(c)){
                recurse(board,(cur->next)[c],ans,x,y);
            }
            x--;
        }
        //checkUP
        if (y>0){
            y--;
            char c = board[y][x];
            if ((cur->next).contains(c)){
                recurse(board,(cur->next)[c],ans,x,y);
            }
            y++;
        }
        //checkdonw
        if (y<ytot-1){
            y++;
            char c = board[y][x];
            if ((cur->next).contains(c)){
                recurse(board,(cur->next)[c],ans,x,y);
            }
            y--;
        }

        //cleanup
        board[y][x]=ogchar;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ans;
        WordDictionary dict;
        
        for (string word:words){
            dict.addWord(word);
        }
        for (int row = 0;row<board.size();row++){
            for (int col = 0;col<board[0].size();col++){
                char c = board[row][col];
                // Only kick off if the character is a valid starting letter in our Trie!
                if (dict.head->next.contains(c)) {
                    recurse(board, dict.head->next[c], ans, col, row);
                }
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};
