class Solution:
    def isValid(self, s: str) -> bool:
        # Map of closing to opening brackets
        bracket_map = {")": "(", "}": "{", "]": "["}
        stack = []

        for char in s:
            if char in bracket_map:
                # Pop the top element if stack is not empty, else use a dummy value
                top_element = stack.pop() if stack else '#'
                
                # Check if the popped opening bracket matches the current closing one
                if bracket_map[char] != top_element:
                    return False
            else:
                # It's an opening bracket, push it onto the stack
                stack.append(char)

        # If stack is empty, all brackets were matched
        return not stack
