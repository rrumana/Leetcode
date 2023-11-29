This was a really fun challenge for me, I like roman numerals

--------------------------

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
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:
  Input: num = 3
  Output: "III"
  Explanation: 3 is represented as 3 ones.

Example 2:
  Input: num = 58
  Output: "LVIII"
  Explanation: L = 50, V = 5, III = 3.

Example 3:
  Input: num = 1994
  Output: "MCMXCIV"
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
  1 <= num <= 3999

------------------------------

Approach details follow:

My approach is a really simple one where I have a while loop run until the number that is passed in has been brought down to zero. I then hard coded all of the possible character sequences because there werent that many of them. The code would have been much faster if I had put this into a hashmap but I couldn't be bothered.

There is also an O(1) solution that involved hard coding, but that is evenb more tedious to type out, but not by much.

------------------------------

Complexity details follow:

Concerning the Leetcode algorithm in isolation:
We have a linear time complexity of O(n) where n is the value of nums passed in. As n increases towards infinity, there would just be an infinite string of 'M's. The implied constant on n is likely some small decimal, but the time complexity is still O(n) making this naive solution much slower than constnt time solutions that consume more memory as num increases.
We have a constant space complexity since we only need to create one new string and add no new data structures.