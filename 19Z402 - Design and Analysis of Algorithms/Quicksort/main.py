def quicksortmainfunction(object, lowerbound, upperbound):
    pivotelement = object[lowerbound]
    ipointer = lowerbound+1
    jpointer = upperbound
    print(f"PIVOT {pivotelement} ipointer {ipointer} jpointer {jpointer}")

    while ipointer < jpointer:
        while (ipointer <= upperbound) and (object[ipointer] <= pivotelement):
            ipointer += 1
        print(f"IPOINTER set at index {ipointer} val {object[ipointer]}")
        while (object[jpointer] > pivotelement):
            jpointer -= 1
        print(f"JPOINTER set at index {jpointer} val {object[jpointer]}")

        if ipointer < jpointer:
            object[ipointer], object[jpointer] = object[jpointer], object[ipointer]
            print("IPOINTER < JPOINTER, SWAP")
            print(object)


    object[jpointer], object[lowerbound] = object[lowerbound], object[jpointer]
    print(f"SWAP JPOINTER({object[jpointer]}@{jpointer}) and LOWERBOUND({object[lowerbound]}@{lowerbound})")
    print(object)
    print("\n\n")

    return jpointer

def quicksortprefunction(targetobject, targetlowerbound, targetupperbound):
    if targetlowerbound < targetupperbound:
        middleelement = quicksortmainfunction(targetobject, targetlowerbound, targetupperbound)
        print(f"ME {targetobject[middleelement]} at index {middleelement}")
        quicksortprefunction(targetobject, targetlowerbound, middleelement-1)
        quicksortprefunction(targetobject, middleelement+1, targetupperbound)

arrayobject = [1, 3, 8, 7, 9, 5, 4, 2, 6, 10]
quicksortprefunction(arrayobject, 0, len(arrayobject)-1)

print(arrayobject)
