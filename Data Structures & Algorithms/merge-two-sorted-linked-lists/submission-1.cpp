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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curA = list1;
        ListNode* curB = list2;
        if (curA==nullptr) return curB;
        else if (curB==nullptr) return curA;
        if (curA->val<=curB->val) {
            head = list1;
            curA = curA->next;
            head -> next = nullptr;
        } else {
            head = list2;
            curB = curB->next;
            head -> next = nullptr;
        }
        ListNode* cur = head;
        while (true){
            cout<<cur->val<<endl;
            if (!(curA || curB)) break;
            if (curA && !curB) {
                cur->next=curA;
                break;
            }
            if (curB && !curA){
                cur->next=curB;
                break;
            } else {
                cout << "COMPARING "<<curA->val <<' '<<curB->val<<endl;
                if (curA->val<=curB->val) {
                    cur->next = curA;
                    cur=cur->next;
                    curA = curA->next;
                    cur -> next = nullptr;
                } else {
                    cur->next = curB;
                    cur=cur->next;
                    curB = curB->next;
                    cur -> next = nullptr;
                }
            }
            
        }
        return head;
    }
};
