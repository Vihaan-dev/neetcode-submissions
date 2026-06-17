/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneRecurse(Node* node, unordered_map<int,Node*> & maps){
        if (!node) return nullptr;
        int val = node->val;
        auto newn = new Node(val);
        maps[val]=newn;
        for (auto neighbor:node->neighbors){
            if (maps.contains(neighbor->val) ){
                (newn->neighbors).push_back(maps[neighbor->val]);
            } else {
                (newn->neighbors).push_back(cloneRecurse(neighbor,maps));
            }
        }
        return newn;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> maps;
        return cloneRecurse(node,maps);
    }
};
