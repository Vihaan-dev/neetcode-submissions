class Node {
public:
    unordered_map<char,Node*> next;
    char c;
    bool end;
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
            if (i==word.size()-1) (cur->end)=true;
        }
    }
    bool search2(span<char> word, Node* cur){
        if (word.size()==0 && cur->end) return true;
        char c = word[0];
        span<char> newword=word.subspan(1);
        if(c=='.'){
            for (auto &[k,v]:cur->next){
                if (search2(newword,v)) return true;
            }
            return false;
        } else {
            if ((cur->next).contains(c)){
                return search2(newword,(cur->next)[c]);
            } else return false;
        }
    }
    bool search(string word) {
        auto cur=head;
        
        return search2(span<char>( word), cur);
    }
};
