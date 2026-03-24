class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val != ".":
                    # Unique keys for row, column, and 3x3 box
                    items = [(r, val), (val, c), (r // 3, c // 3, val)]
                    for it in items:
                        if it in seen: return False
                        seen.add(it)
        return True
