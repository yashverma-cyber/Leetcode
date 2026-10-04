// Source : https://leetcode.com/problems/maximum-subarray/
// Date   : 03-10-2026

/* Q) 53. Maximum Subarray (Easy)
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.   */

class Solution
{

    /* Approach: Use **Kadane's Algorithm**.
       Keep track of the current sum and the maximum sum found so far.
       If the current sum becomes negative, reset it to 0.
       The maximum sum will be the answer. */
    // Time Complexity : O(n)

public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int ans = INT_MIN;

        for (const int num : nums)
        {

            sum = max(num, sum + num);
            ans = max(sum, ans);
        }
        return ans;
    }
};