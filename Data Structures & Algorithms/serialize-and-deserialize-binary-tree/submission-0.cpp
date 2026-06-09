/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
    string s;
    stringstream ss;
public:

    // Encodes a tree to a single string.
    /*string serialize(TreeNode* root) {
        stringstream ss;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()){
            auto el = todo.pop();
            if (el){
                ss<<el->val<<',';
                todo.push(el->left);
                todo.push(el->right);
            } else {
                ss<<"null,";
            }
        }
        return ss.str();
    }*/

    void dfs(TreeNode* node){
        if (!node){
            ss<<"null,";return;
        }
        ss<<node->val<<',';
        dfs(node->left);
        dfs(node->right);
        return;
        
    }

    string serialize(TreeNode* root) {
        
        ss.str("");
        dfs(root);
        return ss.str();

    }
    TreeNode* dfsreader(){
        string temp;
        getline(ss,temp,',');
        if (temp=="null"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(temp),dfsreader(),dfsreader());
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        ss.str(data);
        return dfsreader();
    }
};
