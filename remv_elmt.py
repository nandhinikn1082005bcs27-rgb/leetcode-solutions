from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # k tracks the position for the next element that is NOT 'val'
        k = 0
        
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
                
        # The first k elements are now the ones we want to keep
        return k
