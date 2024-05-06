def issafe(qlist, xpos, ypos):
    for qxpos, qypos in qlist:
        if qxpos == xpos or qypos == ypos:
            return False
        if abs((qxpos - xpos) / (qypos - ypos)) == 1:
            return False
    return True

def placequeens(grid, qlist, qcount):
    if qcount == len(grid[0]):
        print(grid, "\n\n")
        return
    allsafecells = []
    for cell in range(len(grid[0])):
        if issafe(qlist, qcount, cell):
            allsafecells.append([qcount, cell])

    for cell in allsafecells:
        qlist.append(cell)
        grid[cell[0]][cell[1]] = f"Q{qcount}"
        placequeens(grid, qlist, qcount + 1)
        grid[cell[0]][cell[1]] = 0
        qlist.pop()


board = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
queenslist = []
placequeens(board, queenslist, 0)