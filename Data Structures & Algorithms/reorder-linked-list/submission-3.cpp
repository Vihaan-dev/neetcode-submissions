/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        auto slow = head;
        auto fast = head;
        int count = head?1:0;
        while (fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            count+=2;
        } if (fast->next){
            count ++;
            fast=fast->next;
        }
        //cout << slow->val<<' '<<fast->val<<endl;
        //SLOW AND FAST HAVE REACHED THEIR POSITIONS
        
        // =================================================================
        // START OF MODIFICATION: Clean, Universal Reversal Part
        // =================================================================
        
        ListNode* curr = slow->next; // Start from the node right after middle
        slow->next = nullptr;        // Sever the first half from the second half
        
        ListNode* prevN = nullptr;   // Keeps track of the node behind us
        ListNode* nextB = nullptr;   // Temporarily saves the node ahead of us
        
        // This loop handles any list size (even or odd) safely without crashing
        while (curr != nullptr) {
            nextB = curr->next;      // 1. Save the rest of the list
            curr->next = prevN;      // 2. Flip the pointer backward
            prevN = curr;            // 3. Move prevN up to the current node
            curr = nextB;            // 4. Move curr to the saved next node
        }
        
        // At the end of the loop, 'prevN' is standing on the new head 
        // of the reversed second half. Assign it to your original variable 'curB'.
        auto curB = prevN; 
        
        // =================================================================
        // END OF MODIFICATION
        // =================================================================

        auto cur = head;
        auto curA=head;
        auto curAt=curA;
        auto curBt=curB;
        while (curAt){
            cout << curAt->val<<' ';
            curAt=curAt->next;

        }
        cout <<endl;
        while (curBt){
            cout << curBt->val<<' ';
            curBt=curBt->next;

        }
        bool flag = true;
        curA=curA->next;
        while (true){
            if (flag && curB){
                cur->next=curB;
                curB=curB->next;
                cur=cur->next;
                flag=false;

            } else if (!flag && curA){
                cur->next=curA;
                curA=curA->next;
                cur=cur->next;
                flag=true;
            } else break;
        }
    }
};