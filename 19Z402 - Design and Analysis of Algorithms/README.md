# 19Z402 Design and Analysis of Algorithms

## Quicksort Algorithm

1. Select a pivot element from the array.
2. Initialize a pointer `i` to the element immediately following the pivot.
3. Implement a loop that increments `i` until an element greater than the pivot is found.
4. Initialize another pointer `j` at the last position of the array.
5. Implement a second loop that decrements `j` until an element less than the pivot is found.
6. Compare the positions of `i` and `j`.
7. If `i` is less than `j`, swap the elements at the `i`th and `j`th positions.
8. Repeat steps 3-7 until the entire array is sorted.