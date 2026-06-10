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

    ListNode* reverse(ListNode* l1){
        ListNode* cur=l1;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1=l1;
        ListNode* rl2=l2;
        int i=0,j=0,cnt=0;
        ListNode* ans=NULL;
        ListNode* temp=ans;
        while(rl1!=NULL && rl2!=NULL){
            int val=rl1->val+rl2->val+cnt;
            ListNode* newnode=new ListNode(val%10);
            if(temp==NULL){
                ans=temp=newnode;
            }else{
                temp->next=newnode;
                temp=temp->next;
            }
            rl1=rl1->next;
            rl2=rl2->next;
            cnt=val/10;
        }
        if(rl1==NULL){
            swap(rl1,rl2);
        }
        while(rl1!=NULL){
            int val=rl1->val+cnt;
            temp->next=new ListNode(val%10);
            rl1=rl1->next;
            temp=temp->next;
            cnt=val/10;
        }
        if(cnt==1){
            temp->next=new ListNode(1);
        }
        return ans;
    }
};