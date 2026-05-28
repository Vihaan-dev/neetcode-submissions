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
    bool hasCycle(ListNode* head) {
        set<ListNode*> track;
        int index=-1;
        while (head!=nullptr){
            auto it  = track.find(head->next);
            if (it!=track.end()){
                index=distance(track.begin(),it);
                cout <<index;
                return true;
            } else {
                track.insert(head->next);
            }
            head=head->next;
        }
        return false;
    }
};
