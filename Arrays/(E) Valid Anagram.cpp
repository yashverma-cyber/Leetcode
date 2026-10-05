// Source : https://leetcode.com/problems/valid-anagram/
// Date   : 05-10-2026

/* 242. Valid Anagram (Easy)
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true */

class Solution
{
    /* Approach: Use a frequency array to count the occurrences of each character in both strings.
    If the frequency arrays are identical, then the strings are anagrams. */
    // A better (Hashing) approach in ../Hashing/(E) Valid Anagram.cpp
public:
    bool isAnagram(string s, string t)
    {

        int cnt[26] = {0};
        if (size(s) != size(t))
            return false;
        for (int i = 0; i < size(s); ++i)
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] != 0)
                return false;
        }
        return true;
    }
};
