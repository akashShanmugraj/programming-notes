def quicksortmainfunction(object, lowerbound, upperbound):
    pivotelement = object[lowerbound]
    ipointer = lowerbound+1
    jpointer = upperbound

    while ipointer < jpointer:
        while (ipointer <= upperbound) and (object[ipointer] <= pivotelement):
            ipointer += 1
        while (object[jpointer] > pivotelement):
            jpointer -= 1
        
        if ipointer < jpointer:
            object[ipointer], object[jpointer] = object[jpointer], object[ipointer]
        
    object[jpointer], object[lowerbound] = object[lowerbound], object[jpointer]
    
    return jpointer

def quicksortprefunction(targetobject, targetlowerbound, targetupperbound):
    if targetlowerbound < targetupperbound:
        middleelement = quicksortmainfunction(targetobject, targetlowerbound, targetupperbound)
        quicksortprefunction(targetobject, targetlowerbound, middleelement-1)
        quicksortprefunction(targetobject, middleelement+1, targetupperbound)
    

arrayobject = [10, 1, 2, 14, 6, 8, 20, 11]
quicksortprefunction(arrayobject, 0, len(arrayobject)-1)

print(arrayobject)