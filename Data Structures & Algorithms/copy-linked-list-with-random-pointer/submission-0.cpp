/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> maps;
        auto cur=head;
        
        while (cur){
            auto n = new Node(cur->val);
            Node* p = n;
            maps[cur]=p;
            cur = cur->next;
        }
        cur = head;
        auto newhead=maps[cur];
        auto curNew = newhead;
        auto prev=nullptr;
        while (cur){
            Node* p = maps[cur];
            p->next=maps[cur->next];
            p->random = maps[cur->random];
            cur=cur->next;
        }
        return newhead;

    }
};
