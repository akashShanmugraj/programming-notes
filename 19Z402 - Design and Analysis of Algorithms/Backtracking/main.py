def issafe(queens, xpos, ypos):
    for qxpos, qypos in queens:
        if qxpos == xpos or qypos == ypos:
            return False
        if abs((qxpos - xpos) / (qypos - ypos)) == 1:
            return False
    return True


board = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
queenslist = []
queenscounter = 0


def recurplace(grid, qlist, qcount):
    # find a suitable position in the qcount-th row
    if qcount == len(grid[0]):
        print(grid, "\n\n")
        return True
    suitablecells = []
    for cell in range(len(grid[0])):
        if issafe(qlist, qcount, cell):
            suitablecells.append([qcount, cell])

    for cell in suitablecells:
        qlist.append(cell)
        grid[cell[0]][cell[1]] = f"Q{qcount}"
        recurplace(grid, qlist, qcount + 1)
        grid[cell[0]][cell[1]] = 0
        qlist.pop()


def recurstart(grid, qlist):
    for qc in range(len(grid[0])):
        recurplace(grid, qlist, qc)


recurstart(board, queenslist)
