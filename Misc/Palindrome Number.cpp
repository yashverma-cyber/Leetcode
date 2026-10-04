// Source : https://leetcode.com/problems/palindrome-number/
// Date   : 04-10-2026

/* Q9. Palindrome Number (Easy)
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left,
it becomes 121-. Therefore it is not a palindrome.    */

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int n = x;
        long long rev = 0;
        while (n > 0)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev == x;
    }
};