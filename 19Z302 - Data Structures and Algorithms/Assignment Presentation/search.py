# import modules
from time import sleep
from os import system

# open the maze.txt file and read the data
mazeMap = open('maze.txt','r')
mazeRawData = mazeMap.readlines()

mazeArrayData = []
system('clear')
print('\nData extracted from maze.txt:\n')

# removing the \n from the data and storing it in a list
# ['#', '#', 'B', '#', '#', '#', '#', '#', '#', '#', '#', '\n']
# ['#', ' ', ' ', '#', '#', ' ', ' ', ' ', '#', '#', '#', '\n']
# ['#', ' ', '#', '#', '#', '#', '#', '#', 'A', ' ', '#', '\n']
# ['#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '\n']
# ['#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#']

# todo try popping the \n from the list
for iterations in mazeRawData:
    fIter = iterations.replace('\n','')
    mazeArrayData.append([fIter])
    print(fIter)

# puzzleLength x sectionLength is the total size of the puzzle
puzzleLength = len(mazeArrayData)
sectionLength = len(mazeArrayData[0][0])
termination = False

# mazeArrayData would look like [['##B########'], ['#  ##   ###'], ['# ######A #'], ['#     ### #'], ['#####     #']]

availableData = {
    'aPos':None, # [row,column] of source / start
    'bPos':None, # [row,column] of destination / end
    'pathData':[] # all possible empty spaces, aka path
}

for row in range(puzzleLength):
    for column in range(sectionLength):
        element = mazeArrayData[row][0][column]
        if element == 'A':
            availableData['aPos'] = [row,column]
        elif element == 'B':
            availableData['bPos'] = [row,column]
        elif element == ' ':
            availableData['pathData'].append([row,column])

input()
system('clear')

# returns array of possible movement from given coordinates
def neighbourhood(rowPos,columnPos, dataArray):
    possibleSlots = [[rowPos+1,columnPos],[rowPos-1,columnPos],[rowPos,columnPos+1],[rowPos,columnPos-1]]
    availableSlots = []
    for slot in possibleSlots:
        try:
            if dataArray[slot[0]][0][slot[1]] == ' ' or dataArray[slot[0]][0][slot[1]] == 'B':
                availableSlots.append(slot)
        except IndexError:
            pass
        
    print('\nNeighbourhood of',rowPos,columnPos,'is',availableSlots,'\n')
    return availableSlots

# cache for the path moved
moved = []

def move(r, c, terminationState):
    print('\nThe path moved is as described:',moved,'\n')
    print(genPathArt('maze.txt', [r,c]),end = '\r')
    neigh = neighbourhood(r,c,mazeArrayData)
    sleep(0.7)
    input()
    system('clear')

    if availableData['bPos'] in neighbourhood(r,c, mazeArrayData): # if the destination is in the neighbourhood
        termination = True
        f = (genPathArt('maze.txt', [availableData['bPos'][0],availableData['bPos'][1]]))
        for i in range(20):
            print('\nReached B\n')
            print(f)
            sleep(0.7)
            system('clear')
            print('\nReached B\n')
            sleep(0.3)
            system('clear')
            break
        return None
    
    for slot in neigh: # if not in the destination, get possible moves for the root
        newNeigh = neighbourhood(slot[0],slot[1],mazeArrayData) # get the neighbourhood of the new slot
        if not newNeigh:
            print('Maze Terminated at',slot) # if the new slot has no neighbourhood, terminate the maze (aka dead end)
        elif slot in moved: # if the new slot is already moved, continue
            continue
        else:
            moved.append([slot[0],slot[1]]) # if the new slot is not moved, move to the new slot
            if terminationState == True:
                break
            else:
                move(slot[0],slot[1],terminationState) # recursive function to move to the new slot

def genPathArt(filePath, positionList):
    dataFile = open(filePath,'r')
    data = dataFile.read()
    stringList = list(data)
    for markSlot in moved:
        # print(markSlot, )
        stringIndex = markSlot[0] * (sectionLength+1) + markSlot[1]
        stringList[stringIndex] = '▨'
    stringIndex = positionList[0] * (sectionLength+1) + positionList[1]
    if positionList != [availableData['bPos'][0],availableData['bPos'][1]]:
        stringList[stringIndex] = '■'
    finalString = ''
    for element in stringList:
        finalString += element
    return finalString
move(2,8,termination)