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

        ListNode* partition(ListNode* head, int x) {
        ListNode *first_head=new ListNode(0);
        ListNode *second_head=new ListNode(0);
        ListNode *first_tail=first_head,*second_tail=second_head;
        while(head!=nullptr){
            if(head->val>=x){
                second_tail->next=head;
                second_tail=second_tail->next;
            }else{
                first_tail->next=head;
                first_tail=first_tail->next;
            }
            head=head->next;
        }
        second_tail->next=nullptr;
        first_tail->next=second_head->next;
        return first_head->next;
    }

    ListNode* partition_unoptimized(ListNode* head, int x) {
        ListNode *first_head=nullptr;
        ListNode *second_head=nullptr;
        ListNode *first_tail=first_head,*second_tail=second_head;
        while(head!=nullptr){
            if(head->val>=x){
                if(second_head==nullptr){
                    second_head=head;
                    second_tail=second_head;
                }else{
                    second_tail->next=head;
                    second_tail=second_tail->next;
                }
            }else{
                if(first_head==nullptr){
                    first_head=head;
                    first_tail=first_head;
                }else{
                    first_tail->next=head;
                    first_tail=first_tail->next;
                }
            }
            head=head->next;
        }
        // if(first_tail)first_tail->next=nullptr;
        // if(second_tail)second_tail->next=nullptr;
        if(first_head){
            first_tail->next=second_head;
            return first_head;
        }else{
            return second_head;
        }
    }
};