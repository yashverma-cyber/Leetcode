// Source : https://leetcode.com/problems/binary-subarrays-with-sum/
// Date : 07-10-2026

/* Q930. Binary Subarrays With Sum (medium)
Given a binary array nums and an integer goal,
return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]*/

class Solution
{
    /* Approach : Hashing */
    // Sliding Window approach at ../Arrays/(M) Binary Subarrays With Sum.cpp
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        unordered_map<int, int> mpp;
        int currsum = 0;
        int total = 0;
        mpp[0] = 1;
        for (const int n : nums)
        {
            currsum += n;
            if (mpp.find(currsum - goal) != mpp.end())
                total += mpp[currsum - goal];
            mpp[currsum]++;
        }
        return total;
    }
};