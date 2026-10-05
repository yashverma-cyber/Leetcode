// Source : https://leetcode.com/problems/valid-anagram/
// Date   : 05-10-2026

/* 242. Valid Anagram (Easy)
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
 */

class Solution
{

    /* Approach: Hashing
    Normal Array approach in ../Arrays/(E) Valid Anagram.cpp */

    // Explaination of code functions in /Hashing Notes.md

public:
    bool isAnagram(string s, string t)
    {

        if (size(s) != size(t))
            return false;

        unordered_map<char, int> chcnt;

        for (char c : s)
            chcnt[c]++;

        for (char c : t)
        {
            if (chcnt.find(c) == chcnt.end() || chcnt[c] == 0)
                return false;
            chcnt[c]--;
        }
        return true;
    }
};