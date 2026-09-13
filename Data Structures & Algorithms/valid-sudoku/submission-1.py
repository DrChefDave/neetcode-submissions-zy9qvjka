class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for x in range(9):
            array1 = [False] * 10
            array2 = [False] * 10
            array3 = [False] * 10
            for y in range(9):
                num1 = 0 if board[x][y] == "." else ord(board[x][y]) - ord('0')
                num2 = 0 if board[y][x] == "." else ord(board[y][x]) - ord('0')

                x3 = 3*(x // 3) + (y // 3)
                y3 = 3*(x % 3) + (y % 3)

                num3 = 0 if board[x3][y3] == "." else ord(board[x3][y3]) - ord('0')

                if array1[num1] or array2[num2] or array3[num3]:
                    return False;
                else:
                    array1[num1] = False if num1 == 0 else True
                    array2[num2] = False if num2 == 0 else True
                    array3[num3] = False if num3 == 0 else True

        return True




    