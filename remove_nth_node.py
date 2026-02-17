class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Dummy node handles the case where we remove the head
        dummy = ListNode(0, head)
        fast = head
        slow = dummy
        
        # 1. Advance fast pointer n steps ahead
        for _ in range(n):
            fast = fast.next
            
        # 2. Move fast and slow together until fast reaches the end
        while fast:
            fast = fast.next
            slow = slow.next
            
        # 3. slow.next is now the node to remove
        slow.next = slow.next.next
        
        return dummy.next
