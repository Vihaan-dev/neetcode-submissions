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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (!root) return vector<int>();
        q.push(root);
        while (!q.empty()){
            vector<int> anspart;
            int qlen=q.size();
            for (int i = 0;i<qlen;i++){
                auto el = q.front();
                q.pop();
                anspart.push_back(el->val);
                if (el->left) q.push(el->left);
                if (el->right) q.push(el->right);
            }
            ans.push_back(anspart);
        }
        vector<int> newans;
        for (auto el:ans){
            newans.push_back(el[el.size()-1]);
        }
        return newans;
    }
};
