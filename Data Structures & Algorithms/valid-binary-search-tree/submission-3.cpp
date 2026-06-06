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

class Solution {
    bool flag=true;
public:
    void dfs(TreeNode* node,int mi,int ma){
        if (!node) return;
        
        if (!(node->val<ma && node->val>mi)) flag=false;
        
        dfs(node->left,mi,min(ma,node->val));
        dfs(node->right,max(mi,node->val),ma);

    }
    bool isValidBST(TreeNode* root) {
        dfs(root,-10001,10001);
        return flag;
    }
};
