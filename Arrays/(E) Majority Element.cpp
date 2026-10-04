// Source : https://leetcode.com/problems/majority-element/
// Date   : 02-10-2026

/* Q) 169. Majority Element (Easy)
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊n/2⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Example:
Input: nums = [2,2,1,1,1,2,2]
Output: 2   */

class Solution
{

    /* Approach: Use **Boyer-Moore Majority Vote Algorithm**.
       Keep track of a candidate for the majority element and a count.
       If the current element is the same as the candidate, increment the count.
       If it's different, decrement the count.
       If the count becomes 0, update the candidate to the current element.
       The final candidate will be the majority element. */
    // Time Complexity : O(n)

public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ans;
        for (const int num : nums)
        {
            if (count == 0)
                ans = num;
            count += num == ans ? 1 : -1;
        }
        return ans;
    }
};