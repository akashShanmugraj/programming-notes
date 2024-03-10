# Merge Sort Variations

This document provides some interesting variations of the classic Merge Sort Algorithm.

Below is a standard implementation of the Merge Sort Algorithm in Python:

```python
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
```

The `Divide` part of the algorithm remains pretty much the same for all applications, so lets focus on the `Conquer` part:

```python
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
```

The above code is used to merge two sorted array, where the `finalarray` includes duplications.

We can futher modify few lines to get other applications, like _Remove Duplicate Element_ or _Find the element that occurs only once_ in the same flavor of _Divide and Conquer_

> Notice that the `else` statement in `conquer()` means the conditions where the element from firstarray and secondarray both are equal.

# Remove Duplicate Element

In the else part of the `conquer()` function, increment both `firstpointer` and `secondpointer`.
We are appending that duplicate element already once before incrementing the pointers and then we skip both the instances to avoid duplicate append

The `conquer()` would look something like this for the below application

```python
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
```

# Find the element that occurs only once

Finding the element that occurs only once essential means that we need to eliminate the elements that occurs more than once.

We yet again, modify the `else` part of the `conquer()`.
If an element _more than once_, it will be automatically caught in the `else` part (ie `firstarrayobject[firstpointer] == secondarrayobject[secondpointer]`)

To _eliminate_ these pairs with identical element, we can simply increment both pointer and move on without appending that element to the final array.

The `conquer()` would look something like this for the below application

```python
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
            secondpointer += 1
            firstpointer += 1
```
