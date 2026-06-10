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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        int len=0;
        while(temp!=null){
            temp=temp.next;
            len++;
        }
        ListNode cur=head;
        int cnt=0;
        while(cur!=null && cnt<(len-n-1)){
            cur=cur.next;
            cnt++;
        }
        if(len==n){
            return head.next;
        }
        ListNode nxt=cur.next;
        cur.next=nxt.next;
        nxt.next=null;
        return head;
    }
}