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
    int s=INT_MIN;

public:
    int dfs(TreeNode* node){
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        s=max({left+node->val,right+node->val,node->val,left+right+node->val,s});
        return (max(node->val,node->val + max(left,right)));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return s;
    }
};
