// Source : https://leetcode.com/problems/longest-repeating-character-replacement/
// Date : 10-10-2026

/* Q 424. Longest Repeating Character Replacement (medium)
You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.*/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0;
        vector<int> freq(26, 0);
        // Hash Has extra memory overhead for node pointers, bucket arrays, and hash management.
        // Thats why using vector, coz we know size of 26
        int maxfreq = 0;
        int maxLen = 0;

        while (r < size(s))
        {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            if ((r - l + 1 - maxfreq) > k)
            {
                freq[s[l] - 'A']--;
                ++l;
            }

            maxLen = max(maxLen, r - l + 1);
            ++r;
        }
        return maxLen;
    }
};