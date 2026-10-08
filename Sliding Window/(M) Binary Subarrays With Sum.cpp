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
    /* Approach : Sliding Window*/
    // Better Hashing Approach at ../Hashing/(M) Binary Subarrays With Sum.cpp
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        if (goal < 0)
            return 0;
        int l1 = 0, l2 = 0;
        int sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            sum1 += nums[r];
            sum2 += nums[r];
            while (sum1 > goal)
            {
                sum1 -= nums[l1++];
            }
            if (goal > 0)
            {
                while (sum2 > goal - 1)
                {
                    sum2 -= nums[l2++];
                }
            }
            else
            {
                l2 = r + 1;
            }
            cnt1 += r - l1 + 1;
            cnt2 += r - l2 + 1;
        }

        return cnt1 - cnt2;
    }
};