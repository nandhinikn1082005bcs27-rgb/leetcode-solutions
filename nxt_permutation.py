from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n - 2
        
        # 1. Find the first decreasing element from the right
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
            
        if i >= 0:
            # 2. Find the smallest element larger than nums[i] to its right
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            # 3. Swap them
            nums[i], nums[j] = nums[j], nums[i]
        
        # 4. Reverse the suffix (elements after index i)
        # If i was -1, this reverses the whole array (highest to lowest)
        left, right = i + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
