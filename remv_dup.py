from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        # 'k' is the write pointer for the next unique element
        k = 1 
        
        for i in range(1, len(nums)):
            # If current element is different from the previous unique one
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
                
        return k
