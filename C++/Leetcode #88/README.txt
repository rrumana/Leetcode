This was my first coding challenge in quite some time, and with that in mind, it took me quite some time.

--------------------------

The instructions follow:

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

------------------------------

Approach details follow:

The idea is fairly simple, especially with no sorting neccessary.

O(m + n) time is easily achievable by iterating through each element in nums1 and comparing it to nums2.

The hard part was figuring out the logic behind the pointers, and remembering basic C++ syntax for vectors. Specifically, we need to iterate pointer one when a variable is accepted from nums1 and pointer two when one from vairable two is accepted after inserting the element and popping off the back.

------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(m + n) since we only iterate through nums1 of size m + n once.
We have a constant space complexity since we only need to create two counting variables and add no new data structures.

Concerning the file as a whole:
We have a still linear time complexity of O((m + n) * t) where t is a constant but generally unknown number of test cases. Since t does not scale with the size of the array, it is considered constant and does not affect worst case runtime even though with many testcases and small m & n values it could behave closer to (m + n)^2 or worse.
We have a linear space complexity of O((m + 2n) * t) because we need to use O(m + n) amount of space per test case. The same logic about testcase scaling applies here as well.