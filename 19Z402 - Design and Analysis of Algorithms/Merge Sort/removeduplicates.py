unsortedarray = [2, 2, 4, 4, 5, 6, 6, 8, 8, 10, 11, 11, 13, 13]


def conquer(firstarrayobject, secondarrayobject):
    firstpointer, secondpointer = 0,0
    finalarray = []
    while firstpointer < len(firstarrayobject) and secondpointer < len(secondarrayobject):
        if firstarrayobject[firstpointer] < secondarrayobject[secondpointer]:
            finalarray.append(firstarrayobject[firstpointer])
            firstpointer += 1
        elif firstarrayobject[firstpointer] > secondarrayobject[secondpointer]:
            finalarray.append(secondarrayobject[secondpointer])
            secondpointer += 1
        else:
            finalarray.append(secondarrayobject[secondpointer])
            secondpointer += 1
            firstpointer += 1

    if (firstpointer < len(firstarrayobject)):
        finalarray.extend(firstarrayobject[firstpointer:])

    if (secondpointer < len(secondarrayobject)):
        finalarray.extend(secondarrayobject[secondpointer:])

    return finalarray

def divide(arrayobject, lowerbound, upperbound):
    if not(lowerbound < upperbound):
        return arrayobject[lowerbound:upperbound+1]

    middleground = int((lowerbound+upperbound)/2)
    leftsplit = divide(arrayobject, lowerbound, middleground)
    rightsplit = divide(arrayobject, middleground+1, upperbound)
    print(leftsplit, rightsplit, conquer(leftsplit, rightsplit))
    return conquer(leftsplit, rightsplit)

print(divide(unsortedarray, 0, len(unsortedarray)))
