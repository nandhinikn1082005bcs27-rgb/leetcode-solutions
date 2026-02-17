import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Min-heap to store (value, list_index, node)
        heap = []
        
        # 1. Initial push: heads of all non-empty lists
        for i, head in enumerate(lists):
            if head:
                heapq.heappush(heap, (head.val, i, head))
        
        dummy = ListNode(0)
        curr = dummy
        
        # 2. Extract min and replenish heap
        while heap:
            val, i, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            
            # If the extracted node has a successor, push it to the heap
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
        
        return dummy.next
