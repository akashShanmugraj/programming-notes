def quicksort(array, low, high):
    if low < high:
        pivot_index = partition(array, low, high)
        quicksort(array, low, pivot_index)
        quicksort(array, pivot_index + 1, high)

def partition(array, low, high):
    pivot = array[low]
    store_index = low + 1
    for i in range(low + 1, high):
        if array[i] <= pivot: 
            array[i], array[store_index] = array[store_index], array[i]
            store_index += 1
    array[low], array[store_index - 1] = array[store_index - 1], array[low]
    return store_index - 1

array = [1, 3, 8, 7, 9, 5, 4, 2, 6, 10]
quicksort(array, 0, len(array))

print(array)