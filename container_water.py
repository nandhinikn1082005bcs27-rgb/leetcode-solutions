class Solution(object):
    def isMatch(self, s, p):
        memo = {}

        def dp(i, j):
            # Check if we already calculated this state
            if (i, j) in memo:
                return memo[(i, j)]
            
            # Base Case: If we reached the end of the pattern
            if j == len(p):
                return i == len(s)

            # Check if the first characters match
            first_match = i < len(s) and (p[j] == s[i] or p[j] == '.')

            # Handle the '*' wildcard
            if j + 1 < len(p) and p[j+1] == '*':
                # Case 1: Skip the '*' and its preceding character (match zero times)
                # Case 2: Use the '*' if first characters match (match one or more times)
                ans = dp(i, j + 2) or (first_match and dp(i + 1, j))
            else:
                # Regular match: move both pointers forward
                ans = first_match and dp(i + 1, j + 1)

            memo[(i, j)] = ans
            return ans

        return dp(0, 0)
