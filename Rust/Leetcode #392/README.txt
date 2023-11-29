The instructions follow:

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
  Input: s = "abc", t = "ahbgdc"
  Output: true

Example 2:
  Input: s = "axc", t = "ahbgdc"
  Output: false

Constraints:
  0 <= s.length <= 100
  0 <= t.length <= 104
  s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

------------------------------

Approach details follow:

This is a fast but not very memory efficient solution. The idea is to convert the incoming strings into vectors of char and then walk through each of them with two pointers. At each step we compare the two characters from the two strings. Each time we find a match we iterate the pointer belonging to string s, and if we do not we iterate the pointer relating to string t. if the final count on ptr_1 is equal to the length of s then we know that all of the characters in s where matched with characters in t and that truth value is our answer.
------------------------------

Complexity details follow:

Time complexity: O(n+m)
This solution has a runtime complexity of O(n+m) since in the worst case we would need to fully iterate through each of our new vectors.

Space complexity: O(n+m)
This solution has a memory complexity of O(n+m) because we copy the data from the two strings into new vectors, the two pointers in this case take up a negligable constant amount of memory