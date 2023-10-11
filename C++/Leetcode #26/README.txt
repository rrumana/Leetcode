--------------------------

The instructions follow:

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

------------------------------

Approach details follow:

This one seems hard at first, but because the array is already sorted, it is actually really easy.

We just need to iterate through this array once and delete all duplicate elements, which will all be adjacent.

The hardest part for me was making sure that this method could handle more than two duplicate elements in a row and could remove them in place.

The way I achieved this was by using two indexes that iterate under different circumstances.

One is moved on every for loop iteration, and the other is moved every time two elements do not match.

The outside index can then be returned because it will have been iterated by the number of non-repeating elements in the array minus 1.

------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(n) since we only iterate through nums of size n once.
We have a constant space complexity since we only need to create one counting variable and add no new data structures.

Concerning the file as a whole:
We have a still linear time complexity of O(n * t) where t is a constant but generally unknown number of test cases. Since t does not scale with the size of the array, it is considered constant and does not affect worst case runtime even though with many testcases and small n values it could behave closer to (n)^2 or worse.
We have a linear space complexity of O(n * t) because we need to use O(n) amount of space per test case. The same logic about testcase scaling applies here as well.