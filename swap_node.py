# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node handles empty list and single-node list edge cases
        dummy = ListNode(0, head)
        prev = dummy
        
        while prev.next and prev.next.next:
            # Nodes to be swapped
            first = prev.next
            second = first.next
            
            # Rearranging pointers
            first.next = second.next
            second.next = first
            prev.next = second
            
            # Reinitializing prev for the next pair
            prev = first
            
        return dummy.next
