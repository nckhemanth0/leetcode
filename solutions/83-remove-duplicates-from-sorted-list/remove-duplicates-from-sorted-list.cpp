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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail=head;
        ListNode* slow=head;
        while(tail){
            while(tail && tail->val==slow->val){
                tail=tail->next;
            }
            slow->next=tail;
            slow=slow->next;
        }
        return head;
    }
};