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
public:
    TreeNode* sub( span<int> pre, span<int> in){
        if (pre.size()==0) return nullptr;
        TreeNode* h= new TreeNode(pre[0]);
        int index = distance(in.begin(),find(in.begin(),in.end(),pre[0]));
        span<int> lin = in.first(index);
        span<int> rin = in.last(in.size()-index-1);
        span<int> lpre = pre.subspan(1,index);
        span<int> rpre = pre.subspan(index+1);
        h->left = sub(lpre,lin);
        h->right = sub(rpre,rin);
        return h;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return sub(span<int>(preorder),span<int>(inorder));
    }
};
