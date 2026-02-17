from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        def backtrack(open_count: int, close_count: int, current_s: str):
            # Base Case: String is complete
            if len(current_s) == 2 * n:
                res.append(current_s)
                return
            
            # Rule 1: Add an opening bracket if we haven't reached the limit 'n'
            if open_count < n:
                backtrack(open_count + 1, close_count, current_s + "(")
                
            # Rule 2: Add a closing bracket if it won't break the balance
            if close_count < open_count:
                backtrack(open_count, close_count + 1, current_s + ")")
        
        backtrack(0, 0, "")
        return res
