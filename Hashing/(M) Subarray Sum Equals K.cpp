// Source : https://leetcode.com/problems/subarray-sum-equals-k/
// Date : 07-10-2026
/* Q 560. Subarray Sum Equals K (medium)
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int pre = 0, cnt = 0;
        for (int i = 0; i < size(nums); i++)
        {
            pre += nums[i];
            int left = pre - k;
            cnt += mpp[left];
            mpp[pre] += 1;
        }
        return cnt;
    }
};