targetarray = [2,4,1,3,5,6,1,9]

def inversionpairtrack(firstarray, secondarray, paircount, pairlist):
    for firstelement in firstarray:
        for secondelement in secondarray:
            if firstelement > secondelement and [firstelement, secondelement] not in pairlist:
                paircount[0] += 1
                pairlist.append([firstelement, secondelement])
                

def divideandconquer(arrayobject, lowpointer, highpointer, paircount, pairlist):
    if lowpointer == highpointer:
        return arrayobject[lowpointer:highpointer+1]  # Include highpointer in the slice
    else:
        midpointer = int((lowpointer+highpointer)/2)
        firsthalfarray = divideandconquer(arrayobject, lowpointer, midpointer, paircount, pairlist)
        secondhalfarray = divideandconquer(arrayobject, midpointer+1, highpointer, paircount, pairlist)
        inversionpairtrack(firsthalfarray, secondhalfarray, paircount, pairlist)
        return firsthalfarray + secondhalfarray  # Return the divided parts of the array

pc, pl = [0], []

divideandconquer(targetarray, 0, len(targetarray)-1, pc, pl)

print(pc[0], pl)