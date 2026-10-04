// Source : https://leetcode.com/problems/missing-number/
// Date   : 02-10-2026

/* Q) 268. Missing Number (Easy)
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.*/

class Solution
{

    /* Approach: Use XOR operation to find the missing number.
       XOR all indices and values, the result will be the missing number.
       e.g. 1^2^1 = 2 */
    // Time Complexity : O(n)

public:
    int missingNumber(vector<int> &nums)
    {

        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i)
            ans ^= i ^ nums[i];
        return ans;
    }
};