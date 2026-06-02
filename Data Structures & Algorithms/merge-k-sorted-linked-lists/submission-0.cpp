/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool go=true;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (go){
            int mini=0;
            int minval=INT_MAX;
             go = false;
            for (int i=0;i<lists.size();i++){
                if (lists[i]){
                    go=true;
                    if (lists[i]->val<minval) {mini=i;minval=lists[i]->val;}

                }
            }
            if (go && cur==nullptr){
                head = lists[mini];
                cur = lists[mini];
                lists[mini]=lists[mini]->next;
                cur->next=nullptr;
            } else if (go){
                cur->next=lists[mini];
                lists[mini]=lists[mini]->next;
                cur=cur->next;
                cur->next=nullptr;
            }

        }
        return head;
    }
};
