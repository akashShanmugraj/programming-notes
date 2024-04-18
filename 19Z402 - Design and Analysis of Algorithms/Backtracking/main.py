def issafe(queens, xpos, ypos):
    for (qxpos, qypos) in queens:
        if qxpos == xpos or qypos == ypos:
            return False
        if abs((qxpos-xpos)/(qypos-ypos)) == 1:
            return False
    return True

board = [
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
queenslist = []
queenscounter = 0
def place(grid, qlist, qcounter):
    placed = False
    while qcounter != len(grid)-1:
        for col in range(0, len(grid[0])):
            if issafe(qlist, qcounter, col):
                queenslist.append([qcounter, col])
                grid[qcounter][col] = f'Q{qcounter}'
                placed = True
        qcounter += 1
        if not placed:
            print(f'Cannot place {qcounter}th Queen')

place(board, queenslist, queenscounter)
print(board)