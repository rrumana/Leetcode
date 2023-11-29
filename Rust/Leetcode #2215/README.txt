The instructions follow:

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:
  Input: nums1 = [1,2,3], nums2 = [2,4,6]
  Output: [[1,3],[4,6]]
  Explanation:
    For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
    For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:
  Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
  Output: [[3],[]]
  Explanation:
    For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
    Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 
Constraints:
  1 <= nums1.length, nums2.length <= 1000
  -1000 <= nums1[i], nums2[i] <= 1000

------------------------------

Approach details follow:

This approach is super elegant and I cannot take credit for that. I was able to get this running with some string cheese code that did all of these processes manually because I am inexperienced with Rust and did not know how convenient the baked in features are.

This approach creates multiple hashsets, two reflecting the input vectors, and two more reflecting the unique elements in each using the difference lazy iterator. They are then aggregated together into a vector quite conveniently. 

This code does many things by using built in compound methods, which I am not very used to and which consume lots of memory (by Rust standards anyways) but they do a great job of covering up the many loops needed to do this manually.
------------------------------

Complexity details follow:

Time complexity: O(n)

The most costly thing we do in this method is copying and creating new hashsets / vectors. Even though we do these things many times, the time complexity is still O(n).

Space complexity: O(n)

We copy the original arrays a few time in this approach, but our approach doesn't have a memory usage above O(n) in reality, it just seems high because we repeatedly copy the original arrays.

We could use less memory by only copying the original arrays once, and then iterating through them to remove excess elements, but that approach would be slower and likely isnt the suggestred Rust way.
