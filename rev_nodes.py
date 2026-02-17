class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 1. Check if there are at least k nodes to reverse
        curr = head
        for _ in range(k):
            if not curr:
                return head # Not enough nodes, leave as is
            curr = curr.next
        
        # 2. Reverse the first k nodes
        prev = None
        curr = head
        for _ in range(k):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        # 3. After reversal, 'head' is now the tail of this group.
        # Connect it to the next reversed group.
        if head:
            head.next = self.reverseKGroup(curr, k)
            
        # 4. 'prev' is now the new head of this group
        return prev
