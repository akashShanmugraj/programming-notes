# import modules
from time import sleep
from os import system

# open the maze.txt file and read the data
mazeMap = open('maze.txt','r')
mazeRawData = mazeMap.readlines()

mazeArrayData = []
system('clear')
print('\nData extracted from maze.txt:\n')

# remove newline char from the string iterations, convert it into a list, add it to the mazeArrayData list
for iterations in mazeRawData:
    fIter = iterations.replace('\n','')
    mazeArrayData.append([fIter])
    # Initial Preview from maze.txt for user
    print(fIter)

# puzzleLength x sectionLength is the total size of the puzzle
puzzleLength = len(mazeArrayData) # rows
sectionLength = len(mazeArrayData[0][0]) # columns
termination = False

# availableData is a dictionary that stores the position of A and B and the pathData
# aka cache
availableData = {
    'aPos':None,
    'bPos':None,
    'pathData':[]
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

# print(availableData)
input()
system('clear')

def neighbourhood(rowPos,columnPos, dataArray):
    possibleSlots = [[rowPos+1,columnPos],[rowPos-1,columnPos],[rowPos,columnPos+1],[rowPos,columnPos-1]]
    availableSlots = []
    for slot in possibleSlots:
        try:
            if dataArray[slot[0]][0][slot[1]] == ' ' or dataArray[slot[0]][0][slot[1]] == 'B':
                availableSlots.append(slot)
        except IndexError:
            pass
    return availableSlots

moved = []
def move(r, c, terminationState):
    print('\nThe path moved is as described:',moved,'\n')
    print(genPathArt('maze.txt', [r,c]),end = '\r')
    neigh = neighbourhood(r,c,mazeArrayData)
    sleep(0.7)
    input()
    system('clear')
    if availableData['bPos'] in neighbourhood(r,c, mazeArrayData):
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
    for slot in neigh:

        newNeigh = neighbourhood(slot[0],slot[1],mazeArrayData)
        if not newNeigh:
            print('Maze Terminated at',slot)
        elif slot in moved:
            continue
        else:
            moved.append([slot[0],slot[1]])
            if terminationState == True:
                break
            else:
                move(slot[0],slot[1],terminationState)
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