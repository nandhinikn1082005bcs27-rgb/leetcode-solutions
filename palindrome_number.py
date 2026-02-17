class Solution(object):
    def isPalindrome(self, x):
        # Step 1: Negative numbers are never palindromes (e.g., -121 vs 121-)
        if x < 0:
            return False
        
        # Step 2: Reverse the number using the logic you used in Problem 7
        original = x
        reversed_num = 0
        
        while x > 0:
            digit = x % 10
            reversed_num = (reversed_num * 10) + digit
            x //= 10
        
        # Step 3: Check if the reversed number matches the original
        return original == reversed_num
