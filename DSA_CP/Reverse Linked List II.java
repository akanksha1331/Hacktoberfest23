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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head.next == null || left == right)return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev.next;
        }
        ListNode current = prev.next;
        Stack<ListNode> stack = new Stack<>();
        for (int i = 0; i < right - left + 1; ++i) {
            stack.push(current);
            current = current.next;
        }
        while(!stack.isEmpty()){
            prev.next = stack.pop();
            prev = prev.next;
        }
        prev.next = current;
        return dummy.next;  
    }
}
