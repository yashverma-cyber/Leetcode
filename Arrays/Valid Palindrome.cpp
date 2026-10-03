// Source : https://leetcode.com/problems/valid-palindrome/
// Date   : 03-10-2026

/* Q. 125 Valid Palindrome
A phrase is a palindrome if,
after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters,
it reads the same forward and backward.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.*/

class Solution
{
    /* Approach : Two Pointers
    initialize left pointer to 0 and right pointer to size(s)-1
    and then move them towards each other
    if the characters at the left and right pointers are not equal, return false
    else after loop ends return true*/

public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = size(s) - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                ++l;
            while (l < r && !isalnum(s[r]))
                --r;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }
        return true;
    }
};