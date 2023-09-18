# 19Z310 - Data Structures Laboratory
# Laboratory Submission 1
presented by *Akash Shanmugaraj, 22z255*

## Jump Game(#55, M)
### **Problem Statement**
You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

### **Algorithm**
1. We have the function header `bool canJump(int* nums, int numsSize)`
2. Use a integer `target` variable which is set to the last index number, `numsSize - 1`
3. Iterate through the given integer array from back. If the *sum of the current element* and its *index* is **greater than or equal** to the target, update the target to the current index.
4. Once the `target` value has reached 0, which means if it had reached the first index, then we can conclude that it is possible to jump from first element to the last element

### **Source Code**
```c
bool canJump(int* nums, int numsSize){
    int target = numsSize - 1;
    for (int iterable = numsSize - 2; iterable >= 0; iterable--){
        if (nums[iterable] + iterable >= target){
            target = iterable;
        }
    }
    return target == 0;
}
```

### **Submission Metrics**
Runtime: 48 milliseconds

Memory Usage: 8.6 MB

## Swim in Rising Water (#778,H)
### **Problem Statement**
You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. 

You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square `(n - 1, n - 1)` if you start at the top left square `(0, 0)`

![](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

### **Algorithm**
1. Have a `start` and `end` variable with values from `numberarray[0][0]` and `numberarray[numsize-1][numsize-1]` respectively
2. Access values of current values in all possible directions (up, down, left, right). 
3. Call the same function on the indicies of the minimumvalue of adjacent matrix
4. Maintain a array `path` containing the elements which contains all the elements already crossed
5. Have a integer variable `max`, initialized to the first element and periodically updates its value _if it crosses an element with value greater than itself_
6. After reaching bottom right element, terminate the loop / recursion and return `max`

### **Source Code**
```python
class Solution:
    def move(self, gridmatrix, xpos, ypos, pathlist):
        # find up down left and right elements and call the function on the smallest element
        up = gridmatrix[xpos-1][ypos] if xpos > 0 else 10000
        down = gridmatrix[xpos+1][ypos] if xpos < len(gridmatrix)-1 else 10000
        left = gridmatrix[xpos][ypos-1] if ypos > 0 else 10000
        right = gridmatrix[xpos][ypos+1] if ypos < len(gridmatrix[0])-1 else 10000

        # find the smallest element that hasn't been visited
        smallest = min(val for val in [up, down, left, right] if val not in pathlist)

        # find the position of the smallest element
        if smallest == up:
            xpos -= 1
        elif smallest == down:
            xpos += 1
        elif smallest == left:
            ypos -= 1
        elif smallest == right:
            ypos += 1

        # check if the smallest element is the last element
        if gridmatrix[-1][-1] in [up, down, left, right]:
            pathlist.append(gridmatrix[-1][-1])
            return pathlist
        else:
            pathlist.append(smallest)
            return self.move(gridmatrix, xpos, ypos, pathlist)

    def swimInWater(self, grid):
        path = [grid[0][0]]
        return max(self.move(grid, 0, 0, path))
```

### **Submission Metrics**
Runtime: 90 ms

Memory Usage: 16.9 MB

## Add Two Numbers (#2, M)
### **Problem Statement**
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

### **Algorithm**
1. Firstly normalize the Linked List (if two lists are of unequal size) by adding elements with `0` to the end of required list
2. Iterate through both lists simultaneously add two numbers in that element and carry forward the `carry` if necessary. 
3. Insert the sum without the carry to a new linked list
4. After iterating completely, return the third linked list containing all sum  

### **Source Code**
```c
void normalizelists(struct ListNode * listhead1, struct ListNode * listhead2){
    struct ListNode * iterableelement1 = listhead1, * iterableelement2 = listhead2;
    int lengthoflist1 = 0, lengthoflist2 = 0;

    while(iterableelement1->next != NULL || iterableelement2->next != NULL){
        if(iterableelement1->next != NULL){
            lengthoflist1++;
            iterableelement1 = iterableelement1->next;
        }
        if(iterableelement2->next != NULL){
            lengthoflist2++;
            iterableelement2 = iterableelement2->next;
        }
    }
    
    int difference = lengthoflist1 - lengthoflist2;
    struct ListNode * iterableelement = difference < 0 ? iterableelement1 : iterableelement2;

    for (int iterable = 0; iterable < abs(difference); iterable++){
        struct ListNode * newListNode = getListNode(0);
        iterableelement->next = newListNode;
        iterableelement = iterableelement->next;
    }
}

struct ListNode * addition(struct ListNode * headelement1, struct ListNode * headelement2){

    int carry = 0, arithmeticsum = 0, sum = 0;
    struct ListNode * finalAssignment  =  NULL, * assignvar = finalAssignment;
    struct ListNode * temp1 = headelement1, * temp2 = headelement2;

    while (temp1 != NULL && temp2 != NULL){
        arithmeticsum = temp1->val + temp2->val + carry;
        carry = arithmeticsum / 10;
        sum = arithmeticsum % 10;

        temp1 = temp1->next;
        temp2 = temp2->next;
        
        struct ListNode * newListNode = getListNode(sum);
        if (finalAssignment == NULL){
            finalAssignment = newListNode;
            assignvar = finalAssignment;
        } else {
            assignvar->next = newListNode;
            assignvar = assignvar->next;
        }
    }

    if(carry == 1){
        struct ListNode * newListNode = getListNode(carry);
        assignvar->next = newListNode;
        assignvar = assignvar->next;
    }

    return finalAssignment;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    normalizelists(l1, l2);
    return addition(l1, l2);
}

```

### **Submission Metrics**
Runtime: 16ms

Memory Usage: 7.7 MB

## Kth Largest Element in an Array (#215, M)
### **Problem Description**
Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

### **Algorithm**
1. Initialize an integer array `frequency` of size 20001 with all elements set to 0. This array will be used to store the frequency of each integer in the input array.

2. Iterate over the `nums` array from index 0 to `numsSize - 1`.

3. For each element in the `nums` array, calculate its index in the `frequency` array by adding 10000 to the element's value. Increment the value at that index in the `frequency` array by 1.

4. Iterate through the frequency array from back, i.e., from index 20000 to 0

5. For each element in the `frequency` array, subtract its value from `k`. If `k` is less than or equal to 0, return the integer value corresponding to the current index in the `frequency` array minus 10000.

### **Source Code**
```c
int findKthLargest(int* nums, int numsSize, int k) {
    int frequency[20001] = {0};

    for (int i = 0; i < numsSize; i++)
        frequency[nums[i] + 10000]++;

    for (int i = 20000; i >= 0; i--) {
        k -= frequency[i];
        if (k <= 0) return i - 10000;
    }

    return 0;
}
```

### **Submission Metrics**
Runtime: 69 ms

Memory Usage: 11.8 MB

## Contains Duplicate (#216, E)
### **Problem Statement**
Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

### **Algorithm**
1. Create a Hash Map and add every element as the program encounters it
2. Record it's presence by incrementing the respective hash, i.e., its occurence
3. While checking element, if any element's respective hash value is non-zero, (was already found) then break the loop and return `True`

### **Source Code**
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        if(nums==null || nums.length==0)
            return false;
        
        HashSet<Integer> hset = new HashSet<Integer>();
        
        for(int idx: nums){
            if(!hset.add(idx)){
                return true;
            }
        }
        return false;
    }
}
```

### **Submission Metrics**
Runtime: 6 ms

Memory Usage: 55.72 MB

