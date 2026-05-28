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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr) return nullptr;
        ListNode* cur=head;
        ListNode* sec = cur->next;
        cur->next=nullptr;
        ListNode* prev=cur;
        if (sec==nullptr) return cur;
        cur=sec;
        while (cur->next!=nullptr){
            sec=cur->next;
            cur->next=prev;
            prev=cur;
            cur=sec;
        }
        cur->next=prev;
        return cur;
    }
};
