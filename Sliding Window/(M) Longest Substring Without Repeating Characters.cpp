// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Date : 08-10-2026

/* Q 3. Longest Substring Without Repeating Characters (medium)
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Note that "bca" and "cab" are also correct answers.*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> freq(128);
        int cnt = 0;
        for (int l = 0, r = 0; r < size(s); ++r)
        {
            ++freq[s[r]];
            while (freq[s[r]] > 1)
                --freq[s[l++]];

            /* THIS SINGLE LINE:
            --count[s[l++]];
            IS EXACTLY EQUAL TO THESE 3 STEPS:
            char charAtLeft = s[l];      // 1. Identify character at left pointer
            count[charAtLeft]--;         // 2. Decrement its count in the frequency array
            l++;                         // 3. Move the left pointer one step to the right*/

            cnt = max(cnt, r - l + 1);
        }
        return cnt;
    }
};