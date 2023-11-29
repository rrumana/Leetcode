The instructions follow:

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

Example 1:
  Input: gain = [-5,1,5,0,-7]
  Output: 1
  Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:
  Input: gain = [-4,-3,-2,-1,4,3,2]
  Output: 0
  Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
 
Constraints:
  n == gain.length
  1 <= n <= 100
  -100 <= gain[i] <= 100

------------------------------

Approach details follow:

This approach is pretty self explanatory from the code, iterate through the given array and test whether the current height is greater than the max height, if it is, then set max to current. By the end of hte loop the max variable will store the maximum net height during the bike ride.

At first I didn't use the dereference for the line current += *x. This approach came from another programmer on Leetcode who was able to beat 100% of Leetcode users in memory usage. I was emulating their solution to see if I could make code that was 100% in speed and memory usage but that was too good to be true.

------------------------------

Complexity details follow:

Time complexity: O(n)

Since there is only one loop iterationg through the given array once, our runtime is O(n).

Space complexity: O(1)

Since no new data structures are created, this approach has a constant memory complexity due to the counters that are created.
