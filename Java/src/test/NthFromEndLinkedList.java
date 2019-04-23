package test;

/**
 * @author Stoyan Lupov
 * @date 12/04/2019
 **/
public class NthFromEndLinkedList {
    //Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static void main(String[] args) {
        NthFromEndLinkedList nth = new NthFromEndLinkedList();
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);


        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);

//        nth.removeNthFromEnd(head, 2);
//        nth.removeNthFromEnd(new ListNode(1), 1);
        nth.removeNthFromEnd(head2, 1);
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        // Advances fast pointer so that the gap between fast and slow is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            fast = fast.next;
        }

        // Move fast to the end, maintaining the gap
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return dummy.next;
    }
}
