This was my second coding challenge in quite some time, but it went much smoother than the first

It is notable that I was much quicker with prototyping test cases that fit with the Leetcode format and was faster at implementing vactors.

--------------------------

The instructions follow:

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

------------------------------

Approach details follow:

The idea is still simple, the challenge is making it elegant. I initially got way too caught up in the details before landing on this approach.

There are probably better approaches, but this one worked for me and is pretty performant.

Since this is an in place algorithm, the goal was to do in in linear runtime, so I started with one iteration through the given array.

I created a pointer to let me know how many elemnts we have that are not the value. This is usefull because it will tell us where to place the next variable, and as an added bonus, can be returned as the answer.

While iterrating through the array: 
if the next item was not equal to the given value, it was moved to the next spot in the array designated for the answer set.
otherwise, it was skipped.

Since the rest of the vector is unchecked, no copying, resizing, or actual deletion of elements is needed, saving lots of time and complexity.

This took me a fair few tries, it struggled mu8ch more because I was trying to make the array pretty with zeroes at the end, an ultimately futile effort.
------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(n) since we only iterate through nums of size n once.
We have a constant space complexity since we only need to create one counting variable and add no new data structures.

Concerning the file as a whole:
We have a still linear time complexity of O((n) * t) where t is a constant but generally unknown number of test cases. Since t does not scale with the size of the array, it is considered constant and does not affect worst case runtime even though with many testcases and small n values it could behave closer to n^2 or worse.
We have a linear space complexity of O((n + 2) * t) because we need to use O(n + 2) amount of space per test case. The same logic about testcase scaling applies here as well.
