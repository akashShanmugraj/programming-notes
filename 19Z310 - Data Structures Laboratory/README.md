# Leetcode Questions for 19Z310 - Data Structures Laboratory
handled by **Dr Lovelyn Rose S**, PSGCT
maintained by Akash Shanmugaraj, Sophomore, PSGCT

## K-th Largest Element (#215)
22nd August 2023


This code is an implementation of an algorithm to find the kth largest element in an array of integers.
The algorithm uses a bucket sort approach to count the frequency of each integer in the array and then iterates through the bucket array in reverse order to find the kth largest element.

The algorithm works by first initializing a bucket array of size 20001, with each element initialized to 0. 
The bucket array is used to count the frequency of each integer in the input array. The input array is iterated over, and for each integer, its frequency is incremented in the bucket array at the index corresponding to the integer value plus 10000. 
This is done to handle negative integers, which can have an index less than 0.

After the bucket array is populated with the frequency of each integer in the input array, the algorithm iterates through the bucket array in reverse order, starting from the largest possible integer value (20000) and moving down to the smallest possible integer value (0). 
For each bucket array element, the algorithm subtracts the frequency of integers in that bucket from the value of k. If k becomes less than or equal to 0, the algorithm returns the integer value corresponding to the current bucket array index minus 10000.

The algorithm has a time complexity of O(n), where n is the size of the input array, since it iterates over the input array once to populate the bucket array and then iterates over the bucket array once to find the kth largest element. 
The space complexity of the algorithm is O(1), since it uses a fixed-size bucket array that does not depend on the size of the input array.