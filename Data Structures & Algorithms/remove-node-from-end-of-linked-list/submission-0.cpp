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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head|| !head->next) return nullptr;
        int count=0;
        auto cur = head;
        while (cur){
            count++;
            cur=cur->next;
        }
        if (count == n) return head->next;
        cur = head;
        for (int i=0;i<count-n-1;i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return head;
    }
};
