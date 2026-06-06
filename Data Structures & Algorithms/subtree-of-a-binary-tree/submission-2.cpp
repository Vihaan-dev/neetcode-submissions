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
    vector<int> r;
    vector<int> subr;
public:
    void dfs(TreeNode* node,vector<int>& l){
        if (node){
            l.push_back(node->val);
            dfs(node->left,l);
            dfs(node->right,l);
        } else {l.push_back(INT_MAX);}
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,r);
        dfs(subRoot,subr);
        for (auto el:r) cout <<el<<' ';
        cout<<endl;
        for (auto el:subr) cout <<el<<' ';
        cout<<endl;
        for (int i=0;i<r.size()-subr.size()+1;i++){
            bool flag=true;
            for (int j=0;j<subr.size();j++){
                if (subr[j]!=r[i+j]){
                    flag=false;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
    }
};
