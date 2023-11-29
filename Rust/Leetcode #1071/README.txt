This was my first coding challenge in Rust, I needed great help from the Rust documentation.

--------------------------

The instructions follow:

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
  Input: str1 = "ABCABC", str2 = "ABC"
  Output: "ABC"

Example 2:
  Input: str1 = "ABABAB", str2 = "ABAB"
  Output: "AB"

Example 3:
 Input: str1 = "LEET", str2 = "CODE"
  Output: ""
 

Constraints:
  1 <= str1.length, str2.length <= 1000
  str1 and str2 consist of English uppercase letters.

------------------------------

Approach details follow:

The idea is simple enough, the math behind it was not immediately obvious to me though since I am unfamiliar with Rust and the tools at my disposal. You can check that the strings are multiples of the same substring by putting them end to end to end in a different order. If the two ways they can go together are equal, then we can proceed on to finding that substring, otherwise we return an empty string.

The can the return the substring of str1 that is the length that the recursive gcd function will return. This function will contrinue to recurse until it finds that mathematical gcd of the two strings' length. This length also happens to correlate with the length of the GCD string that is needed. Since the substring t is evenly concatenated to form str1 and str2, the length from 0-t exclusive of either sting will return the expected answer.
------------------------------

Complexity details follow:

Time complexity: O(m+n)
I originally thought that the time complexity was going to be O(log(n)), but it turns out the most time consuming part of this algorithm is actually the string comparison, which takes O(n+m) time since the string we compare is a concatenation of str1 and str2, which are lengths n and m respectively.

The GCD function time complexity is O(log(n)) since it constantly applies the modulo operator to the starting str1 length.

Space complexity: O(m+n)
The space complexity is O(m+n) because we clone both strings to form our testing substring, which is the bulk of the memory in this program.