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
    int res=0;
public:
    int dfs (TreeNode* el){
        if (!el) return 0;
        int leftlen = dfs(el->left);
        int rightlen = dfs(el->right);
        res=max(res,leftlen+rightlen);
        return (1+max(leftlen,rightlen));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
