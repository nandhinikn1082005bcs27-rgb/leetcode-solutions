class Solution(object):
    def convert(self, s, numRows):
        # Edge case: If only 1 row or string is short, no zigzag happens
        if numRows == 1 or numRows >= len(s):
            return s

        # Create a list of strings, one for each row
        rows = ["" for _ in range(numRows)]
        
        current_row = 0
        step = 1  # 1 means moving down, -1 means moving up

        for char in s:
            rows[current_row] += char
            
            # If we hit the top row, we must go down (step = 1)
            # If we hit the bottom row, we must go up (step = -1)
            if current_row == 0:
                step = 1
            elif current_row == numRows - 1:
                step = -1
            
            current_row += step

        # Join all the rows together into one final string
        return "".join(rows)
