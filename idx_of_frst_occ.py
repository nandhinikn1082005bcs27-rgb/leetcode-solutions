class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        
        # Iterate through haystack where a match is still possible
        for i in range(n - m + 1):
            # Check if substring matches needle
            if haystack[i : i + m] == needle:
                return i
                
        return -1
