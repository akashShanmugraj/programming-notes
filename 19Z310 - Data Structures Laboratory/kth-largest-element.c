#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findKthLargest(int* nums, int numsSize, int k) {
    // Initialize an array to store the frequency of each integer in the input array
    int frequency[20001] = {0};

    // Iterate over the input array and increment the frequency of each integer in the frequency array
    for (int i = 0; i < numsSize; i++) {
        int index = nums[i] + 10000;
        frequency[index]++;
    }

    // Iterate over the frequency array in reverse order and subtract the frequency of each integer from k
    for (int i = 20000; i >= 0; i--) {
        k -= frequency[i];
        if (k <= 0) {
            // Return the integer value corresponding to the current frequency array index minus 10000
            int result = i - 10000;
            return result;
        }
    }

    // If k is greater than the total number of integers in the input array, return 0
    return 0;
}
int main() {
    int nums[] = {3,2,1,5,6,4};
    int k = 2;
    int result = findKthLargest(nums, 6, k);
    printf("%d\n", result);
    return 0;
}