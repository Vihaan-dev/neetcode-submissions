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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryover=-1;
        ListNode* head=new ListNode();
        ListNode* cur=head;
        while (true){
            if (!(l1||l2)&&carryover==-1) break;

            int s=0;
            if (l1){
                s+=l1->val;
                l1=l1->next;
            }
            if (l2){
                s+=l2->val;
                l2=l2->next;
            }
            if (carryover>-1){
                s+=carryover;
                carryover=-1;
            }
            if (s>9){
                carryover=s/10;
                cur->val=s%10;

            }else {cur->val=s;}
            if (l1||l2||carryover>-1){
                cur->next=new ListNode();
                cur=cur->next;
            }

        }
        return head;
        
    }
};
