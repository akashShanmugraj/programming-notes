array1 = [1, 4, 7, 10, 11, 30, 60]
array2 = [2, 3, 5, 8]

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

print(newarray)
