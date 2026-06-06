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
    int count = 0;
public:
    void dfs(TreeNode* node, int m){
        if (!node) return;
        if (node->val>=m){
            count ++;
            m=node->val;
        }
        dfs(node->left,m);
        dfs(node->right,m);

    }
    int goodNodes(TreeNode* root) {
        dfs(root,-101);
        return count;
    }
};
