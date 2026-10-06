// Source : https://leetcode.com/problems/sort-characters-by-frequency/
// Date   : 06-10-2026

/* Q 451. Sort Characters By Frequency (medium)
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.*/

class Solution
{

    /* Approach : Use Maxheap (priority queue)
     each element in maxHeap is a pair<int, char> storing {frequency, character}
     Structured Binding (auto [count, ch] = ...):Unpacks the std::pair
     directly into two separate local variables:
     count gets the first element of the pair (int -> frequency).
     ch gets the second element of the pair (char -> character).
     auto automatically deduces the types (int for count, char for ch).
    */
    // Time Complexity: O(N + logK) = O(N)
    // Auxiliary Space Complexity: O(K) = O(1)

public:
    string frequencySort(string s)
    {
        // 1. Frequency map for ASCII characters
        vector<int> freq(128, 0);
        for (const char c : s)
        {
            freq[c]++;
        }

        // 2. Collect unique characters along with their frequencies
        vector<pair<int, char>> charFreq;
        charFreq.reserve(128);
        for (int i = 0; i < 128; ++i)
        {
            if (freq[i] > 0)
            {
                charFreq.push_back({freq[i], (char)i});
            }
        }

        // 3. Sort by frequency in descending order
        sort(charFreq.begin(), charFreq.end(), [](const auto &a, const auto &b)
             {
                 return a.first > b.first; // sort by higher frequency first
             });

        // 4. Build output string efficiently
        string result;
        result.reserve(s.length()); // Pre-allocate memory to avoid reallocations

        for (const auto &[count, ch] : charFreq)
        {
            result.append(count, ch);
        }

        return result;
    }
};