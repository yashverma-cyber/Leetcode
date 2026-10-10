// Source : https://leetcode.com/problems/minimum-window-substring/
// Leetcode Solution : https://leetcode.com/submissions/detail/2168098049/
// Date : 10-10-2026

/* Q 76. Minimum Window Substring (hard)
Given two strings s and t of lengths m and n respectively,
return the minimum window substring of s such that
every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t. */

// Time Complexity : O(n)
// Space Complexity : O(1) (constant space for the need array of size 128)

/* Why is this O(n)? Even though there is a while (required == 0)
loop nested inside the main while (r < s.size()) loop,
both pointers (l and r) only ever move forward.
r traverses the string from index 0 to n-1.l catches up to r as needed, but never moves backward.
As a result, each character is visited at most twice (once by r, once by l), giving a strict and optimal O(n) time complexity.*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.size() < t.size())
            return "";
        int l = 0, r = 0;
        int minlen = INT_MAX;
        int startidx = -1;
        int need[128] = {0};
        int required = t.size();

        for (const char c : t)
            need[c]++;

        while (r < size(s))
        {
            char rightchar = s[r];

            if (need[rightchar] > 0)
                required--;
            need[rightchar]--;
            r++;

            while (required == 0)
            {
                if (r - l < minlen)
                {
                    minlen = r - l;
                    startidx = l;
                }
                char leftchar = s[l];
                need[leftchar]++;
                if (need[leftchar] > 0)
                    required++;
                l++;
            }
        }
        return startidx == -1 ? "" : s.substr(startidx, minlen);
    }
};