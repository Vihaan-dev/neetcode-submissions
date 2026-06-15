class Node {
public:
    unordered_map<char,Node*> next;
    char c;
    bool end;
    Node(char c, bool end):c(c),end(end){

    }
};

class PrefixTree {
public:
    Node* head;
    PrefixTree() {
        head = new Node('#',false);
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        auto cur = head;
        for (int i = 0;i<word.size();i++){
            char c = word[i];
            if ((cur->next).contains(c)) cur = (cur->next)[c];
            else {
                return false;
            }
            
        }
        if (cur->end) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        auto cur = head;
        for (int i = 0;i<prefix.size();i++){
            char c = prefix[i];
            if ((cur->next).contains(c)) cur = (cur->next)[c];
            else {
                return false;
            }
            
        }
        return true;
        
    }
};
