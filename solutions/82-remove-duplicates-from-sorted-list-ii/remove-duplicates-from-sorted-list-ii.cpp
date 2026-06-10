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
        ListNode* temp=new ListNode(-101);
        temp->next=head;
        ListNode* slow=temp;
        ListNode* fast=temp;
        while(fast){
            int count=0;
            while(fast && fast->next && fast->val==fast->next->val){
                fast=fast->next;
                count++;
            }
            if(count==0){
                slow=fast;
                fast=fast->next;
            }else{
                fast=fast->next;
                slow->next=fast;
            }
        }
        return temp->next;
    }
};