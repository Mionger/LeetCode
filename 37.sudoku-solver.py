#
# @lc app=leetcode id=37 lang=python3
#
# [37] Sudoku Solver
#
class Solution:
    def __init__(self):
        self.rows = None
        self.cols = None
        # 表示3x3的小宫格
        self.spaces = None
        # 标志是否完成
        self.flag = None

    def solveSudoku(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.rows = [[0] * 10 for _ in range(9)]
        self.cols = [[0] * 10 for _ in range(9)]
        self.spaces = [[0] * 10 for _ in range(9)]
        self.flag = False

        # 预处理已经在数独中的元素
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j])
                    self.rows[i][num] = 1
                    self.cols[j][num] = 1
                    self.spaces[self.validate(i, j)][num] = 1
        self.dfs(board, 0, 0)

    def dfs(self, board, x, y):
        #所有位置都已经成功安排了数字，结束
        if x == 9:
            self.flag = True
            return
        #该位置原来有数字
        if board[x][y] != '.':
            if y == 8:
                self.dfs(board, x + 1, 0)
            else:
                self.dfs(board, x, y + 1)
        #该位置没有数字，等待安排
        else:
            # 排查可用数字
            for num in range(1, 10):
                if self.rows[x][num] == 1:
                    continue
                if self.cols[y][num] == 1:
                    continue
                if self.spaces[self.validate(x, y)][num] == 1:
                    continue
                #找到可用数字
                board[x][y] = str(num)
                #标记该数字已使用过
                self.rows[x][num] = 1
                self.cols[y][num] = 1
                self.spaces[self.validate(x, y)][num] = 1
                
                if y == 8:
                    self.dfs(board, x + 1, 0)
                else:
                    self.dfs(board, x, y + 1)

                #结束
                if self.flag:
                    return
                
                #没有全部安排完，回溯，清空原位置
                board[x][y] = '.'
                self.rows[x][num] = 0
                self.cols[y][num] = 0
                self.spaces[self.validate(x, y)][num] = 0

    def validate(self, x, y):
        if 0 <= x < 3:
            if 0 <= y < 3:
                return 0
            elif 3 <= y < 6:
                return 1
            else:
                return 2
        elif 3 <= x < 6:
            if 0 <= y < 3:
                return 3
            elif 3 <= y < 6:
                return 4
            else:
                return 5
        else:
            if 0 <= y < 3:
                return 6
            elif 3 <= y < 6:
                return 7
            else:
                return 8

