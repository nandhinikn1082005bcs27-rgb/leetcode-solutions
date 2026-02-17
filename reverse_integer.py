class Solution(object):
    def reverse(self, x):
        # Define the 32-bit signed integer boundaries
        MAX_INT = 2147483647
        MIN_INT = -2147483648

        # Handle the negative sign
        res = 0
        sign = 1 if x >= 0 else -1
        x = abs(x)

        while x != 0:
            # Get the last digit
            digit = x % 10
            # Remove the last digit from x
            x //= 10
            
            # Check for overflow before updating res
            if res > (MAX_INT - digit) // 10:
                return 0
                
            res = (res * 10) + digit

        return res * sign
