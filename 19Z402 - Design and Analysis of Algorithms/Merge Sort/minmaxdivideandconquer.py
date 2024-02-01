unsortedarray = [22, 10, 3, 14, 6, 8, 0, 20, 11]

lowpointer, highpointer = 0, len(unsortedarray) - 1


def merge_sorted_arrays(array1, array2):
    pointer1, pointer2 = 0, 0
    length1, length2 = len(array1), len(array2)
    newarray = []

    while pointer1 < length1 and pointer2 < length2:
        if array1[pointer1] < array2[pointer2]:
            newarray.append(array1[pointer1])
            pointer1 += 1
        elif array1[pointer1] > array2[pointer2]:
            newarray.append(array2[pointer2])
            pointer2 += 1
        elif array1[pointer1] == array2[pointer2]:
            newarray.append(array1[pointer1])
            pointer1 += 1

    if pointer1 < length1:
        newarray.extend(array1[pointer1:])
    elif pointer2 < length2:
        newarray.extend(array2[pointer2:])

    return newarray


def minimum(lowpointer, highpointer, arrayobject):
    if not (lowpointer < highpointer):
        return arrayobject[lowpointer : highpointer + 1]
    midpointer = int((lowpointer + highpointer) / 2)
    leftsplit = minimum(lowpointer, midpointer, arrayobject)
    rightsplit = minimum(midpointer + 1, highpointer, arrayobject)
    return leftsplit if leftsplit<rightsplit else rightsplit

def maximum(lowpointer, highpointer, arrayobject):
    if not (lowpointer < highpointer):
        return arrayobject[lowpointer : highpointer + 1]
    midpointer = int((lowpointer + highpointer) / 2)
    leftsplit = maximum(lowpointer, midpointer, arrayobject)
    rightsplit = maximum(midpointer + 1, highpointer, arrayobject)
    return rightsplit if leftsplit<rightsplit else leftsplit


print(minimum(lowpointer, highpointer, unsortedarray))
print(maximum(lowpointer, highpointer, unsortedarray))
