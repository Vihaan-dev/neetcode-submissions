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
    bool balanced=true;
public:
    int dfs (TreeNode* el){
        if (!el) return 0;
        int left = dfs(el->left);
        int right = dfs(el->right);
        if (abs(right-left)>1) balanced=false;
        return (1+max(left,right));
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }
};
