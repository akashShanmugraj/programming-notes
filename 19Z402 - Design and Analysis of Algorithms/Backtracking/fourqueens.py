from typing import List


class FourQueens:
    def issafe(
        self, listofqueens: List[List[int]], xposition: int, yposition: int
    ) -> bool:
        for queenxposition, queenyposition in listofqueens:
            if queenxposition == xposition or queenyposition == yposition:
                return False
            if abs((queenxposition - xposition) / (queenyposition - yposition)) == 1:
                return False
        return True

    def placequeens(
        self, grid: List[List[int]], listofqueens: List[List[int]], queencounter: int
    ):
        if queencounter == len(grid[0]):
            print(grid, "\n\n")
            return

        allsafecells = []

        for cell in range(len(grid[0])):
            if self.issafe(listofqueens, queencounter, cell):
                allsafecells.append([queencounter, cell])

        for xposition, yposition in allsafecells:
            listofqueens.append([xposition, yposition])
            grid[xposition][yposition] = f"Q{queencounter}"
            self.placequeens(grid, listofqueens, queencounter + 1)
            grid[xposition][yposition] = 0
            listofqueens.pop()


board = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
queenslist = []
fourqueensobject = FourQueens()
fourqueensobject.placequeens(board, queenslist, 0)
