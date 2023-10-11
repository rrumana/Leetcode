This was my first medium difficulty coding challenge, and even though this was very similar to #26, it was much harder.

--------------------------

The instructions follow:

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

------------------------------

Approach details follow:

This one is just like #26 but it can have two of each instead of one.

We just need to iterate through this array once and delete all duplicate elements resulting in 3 or more copies, which will all be adjacent.

The hardest part for me was figuring out how to keep track of how many copies of each element are present and moving it down to 2.

Even though the challenge is really similar, I used a very different approach.

We still create two iterators, one only used for loop iteration and one used to keep track of unique elements in the array.

If the indices are equal and too close together, the leading index is iterated, otherwise the element located at the leading index is erased.

The size of the array is returned because the iterators can sometimes straddle the last element if there is an odd number of elements, and so size is used instead of hard coding it like in #26. 

------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(n) since we only iterate through nums of size n once. It is important to note that the .size() method for vectors takes constant time since the size value is stored.
We have a constant space complexity since we only need to create one counting variable and add no new data structures.

Concerning the file as a whole:
We have a still linear time complexity of O(n * t) where t is a constant but generally unknown number of test cases. Since t does not scale with the size of the array, it is considered constant and does not affect worst case runtime even though with many testcases and small n values it could behave closer to (n)^2 or worse.
There is another constant factor for the comparisons of the given and expected elements but the time complexity still simplifies down to O(n).
We have a linear space complexity of O(n * t) because we need to use O(n) amount of space per test case. The same logic about testcase scaling applies here as well.