class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Constants for 32-bit signed integer range
        MAX_INT = 2**31 - 1
        MIN_INT = -2**31
        
        # Handle the overflow edge case
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
        
        # Determine the sign of the result
        # Using XOR: result is negative if signs are different
        is_negative = (dividend < 0) ^ (divisor < 0)
        
        # Work with absolute values
        dvd, dvs = abs(dividend), abs(divisor)
        quotient = 0
        
        # Main logic: subtract larger chunks using bit shifting
        while dvd >= dvs:
            temp_divisor, multiple = dvs, 1
            # Double the divisor as long as it's smaller than the remaining dividend
            while dvd >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            
            # Subtract the largest chunk found and add to the quotient
            dvd -= temp_divisor
            quotient += multiple
            
        return -quotient if is_negative else quotient
