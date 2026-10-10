// Source : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Solution : https://leetcode.com/submissions/detail/2168039918/
// Date : 10-10-2026

// Question is locked for premium only....

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Uses a sliding window with character frequencies.
    int longestSubstringAtMostKDistinct(
        string s,
        int k)
    {
        int n = s.size();

        // No valid non-empty substring can exist in these cases.
        if (n == 0 || k <= 0)
        {
            return 0;
        }

        unordered_map<char, int> frequency;

        int left = 0;
        int maxLength = 0;

        // Expand the window with right.
        for (int right = 0; right < n; right++)
        {
            frequency[s[right]]++;

            // Shrink until the window has at most k distinct characters.
            while (frequency.size() > k)
            {
                frequency[s[left]]--;

                // Remove a character only after its last copy leaves.
                if (frequency[s[left]] == 0)
                {
                    frequency.erase(s[left]);
                }

                left++;
            }

            maxLength = max(
                maxLength,
                right - left + 1);
        }

        return maxLength;
    }
};

int main()
{
    string s = "eceba";
    int k = 2;

    Solution solution;

    cout << solution.longestSubstringAtMostKDistinct(s, k) << endl;

    return 0;
}