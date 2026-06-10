/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null){
            return null;
        }
        ListNode temp=head;
        int len=0;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
        k%=len;
        if(k==0){
            return head;
        }
        int cnt=0;
        ListNode prev=head;
        while(cnt<(len-k-1)){
            prev=prev.next;
            cnt++;
        }
        ListNode new_head=prev.next;
        prev.next=null;

        temp=new_head;
        while(temp!=null && temp.next!=null){
            temp=temp.next;
        }
        temp.next=head;
        return new_head;
    }
}