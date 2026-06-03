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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        auto cur = head;
        while (cur){
            count++;
            cur=cur->next;
        }
        vector<pair<ListNode*,ListNode*>> lst;
        cur=head;
        int iter=0;
        while (iter<count/k){
            pair<ListNode*,ListNode*> p;
            p.second = cur;
            ListNode* prev = nullptr;
            for (int i=0;i<k;i++){
                auto next = cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            p.first=prev;
            iter++;
            lst.push_back(p);
        }
        pair pextra(cur,nullptr);
        lst.push_back(pextra);
        auto newhead = lst[0].first;
        for (int i=0;i<lst.size()-1;i++){
            
            lst[i].second->next = lst[i+1].first;
            
        }
        return newhead;
    }
};
