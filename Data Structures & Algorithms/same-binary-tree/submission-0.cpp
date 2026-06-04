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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pval;
        vector<TreeNode*> qval;
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        pq.push(p);
        qq.push(q);
        while (pq.size()>0){
            TreeNode* el = pq.front();
            pq.pop();
            pval.push_back(el);
            if (el){
                pq.push(el->left);
                pq.push(el->right);
            }
        }
        while (qq.size()>0){
            TreeNode* el = qq.front();
            qq.pop();
            qval.push_back(el);
            if (el){
                qq.push(el->left);
                qq.push(el->right);
            }
        }
        for (auto el : pval) {
            if (el) cout << el->val<<' ';
            else cout <<"null";
        }
        cout <<endl;
        for (auto el : qval) {
            if (el) cout << el->val<<' ';
            else cout <<"null";
        }
        cout <<endl;
        bool flag=true;
        for (int i=0;i<pval.size();i++){
            if (!pval[i] && qval[i] || !qval[i] && pval[i]) {flag=false;break;}
            else if (!pval[i]&&!qval[i]) continue;
            else if (pval[i]->val!=qval[i]->val) {
                flag=false;
                cout << pval[i]->val<<' '<<qval[i]->val<<endl;
                break;
            }
        }
        return flag;
    }
};
