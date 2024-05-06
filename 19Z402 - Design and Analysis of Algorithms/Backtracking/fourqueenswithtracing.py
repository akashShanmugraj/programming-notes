import time
def issafe(qlist, xpos, ypos):
    for qxpos, qypos in qlist:
        if qxpos == xpos or qypos == ypos:
            return False
        if abs((qxpos - xpos) / (qypos - ypos)) == 1:
            return False
    return True

def placequeens(grid, qlist, qcount,c):
    if qcount == len(grid[0]):
        print("gridCOMP", "\n\n")
        return
    allsafecells = []
    for cell in range(len(grid[0])):
        if issafe(qlist, qcount, cell):
            allsafecells.append([qcount, cell])
    print("\t"*c[0],"ASFC", allsafecells)
    
    for cell in allsafecells:
        c[0] += 1
        print("\t"*(c[0]-1),"PC(grid, ql, qc)")
        qlist.append(cell)
        grid[cell[0]][cell[1]] = f"Q{qcount}"
        print("\t"*c[0],"PLACE", cell)
        print("\t"*c[0],"QL:", qlist)
        placequeens(grid, qlist, qcount + 1,c)
        grid[cell[0]][cell[1]] = 0
        qlist.pop()
        c[0] -= 1
        print("\t"*c[0],"REMOVE", cell)
        print("\t"*c[0],"QLIST:", qlist)


board = [
    [0, 0, 0, 0], 
    [0, 0, 0, 0], 
    [0, 0, 0, 0], 
    [0, 0, 0, 0], 
]
queenslist = []
t1 = time.time()
placequeens(board, queenslist, 0, [0])
t2 = time.time()
print(t2-t1)