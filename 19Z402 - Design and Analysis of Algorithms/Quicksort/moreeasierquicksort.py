def quicksort(arrayofelements):
    if len(arrayofelements) < 2:
        return arrayofelements
    else:
        
        pivot = arrayofelements[0]
        left = [element for element in arrayofelements[1:] if element <= pivot]
        right = [element for element in arrayofelements[1:] if element > pivot]
        
        return quicksort(left) + [pivot] + quicksort(right)

a = [10,5,2,3]
print(quicksort(a))