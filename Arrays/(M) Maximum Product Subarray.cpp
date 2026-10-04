// Source : https://leetcode.com/problems/maximum-product-subarray/
// Date   : 02-10-2026

/* Q) 152. Maximum Product Subarray (Medium)
Given an integer array nums, find a contiguous non-empty subarray
within the array that has the largest product, and return the product.

​​​​​​​Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.   */

class Solution
{

    /* Approach: Modified Kadane's Algorithm for product
    by adding min-max and swapping for negatives */
    // Time Complexity : O(n)

public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int ans = nums[0];
        int prdmax = 1;
        int prdmin = 1;

        for (const int num : nums)
        {

            if (num < 0)
                swap(prdmax, prdmin);
            prdmax = max(num, prdmax * num);
            prdmin = min(num, prdmin * num);
            ans = max(ans, prdmax);
        }
        return ans;
    }
};