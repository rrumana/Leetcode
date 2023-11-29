The instructions follow:

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:
  Input: s = "III"
  Output: 3
  Explanation: III = 3.

Example 2:
  Input: s = "LVIII"
  Output: 58
  Explanation: L = 50, V= 5, III = 3.

Example 3:
  Input: s = "MCMXCIV"
  Output: 1994
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
  1 <= s.length <= 15
  s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
  It is guaranteed that s is a valid roman numeral in the range [1, 3999].

------------------------------

Approach details follow:

This one was very similar to 12

I actually used a map this time though, so that is a small improvement. This solution is neither the fastest nor the most memory efficient, but it is simple and fast enough for the small implementation we make here.

The combinations are loaded into the map and then similarly to 12 there is a loop that convets roman characters into a rolling sum one character at a time.

There is some difference here because because we need to check if the number is being added or subtracted so we must implement a sliding window technique to check if the current item is bigger or smaller then the following one.

------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(n) where n is the number of character in the given string because we iterate through the string once. The map loading and lookup operations are negligible in this context.
We have a constant space complexity because we are not creating any new items that are bound to the size of the input. We do create a map and a few variables, but they are constant with respect to the input size.