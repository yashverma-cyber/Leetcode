// Source : https://leetcode.com/problems/max-consecutive-ones-iii/
// Date : 08-10-2026

/* Q 1004. Max Consecutive Ones III (medium)
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int zeroes = 0;
        int l = 0, r = 0, cnt = 0;
        while (r < size(nums))
        {
            if (nums[r] == 0)
                zeroes++;
            while (zeroes > k)
            {
                if (nums[l] == 0)
                    --zeroes;
                ++l;
            }
            if (zeroes <= k)
                cnt = max(cnt, r - l + 1);
            ++r;
        }
        return cnt;
    }
};