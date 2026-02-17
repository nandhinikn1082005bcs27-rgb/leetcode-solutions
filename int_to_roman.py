class Solution:
    def intToRoman(self, num: int) -> str:
        # Define mappings in descending order, including subtractive pairs
        value_symbols = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
            (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]
        
        res = []
        for value, symbol in value_symbols:
            if num == 0:
                break
            
            # Determine how many times the current symbol fits into num
            count, num = divmod(num, value)
            # Append the symbol that many times to the result list
            res.append(symbol * count)
            
        return "".join(res)
