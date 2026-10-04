// Source : https://leetcode.com/problems/3sum/
// Date   : 04-10-2026

/* Q 15. 3Sum (medium)
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

class Solution
{

    /* Approach = 2 Pointers,
    i is constant, put j as i+1 and k at end
    we check nums at each position if its summing to 0
    if less than 0 we know -ve part is bigger so move it to right
    if greater than 0 then move end closer */
    // Time Complexity : O(n^2)
    // Space Complexity : O(1) if we don't consider the output array otherwise O(log n) for sorting the array

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int sum = 0;

        for (int i = 0; i < size(nums); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = size(nums) - 1;
            while (j < k)
            {
                sum = nums[i] + nums[k] + nums[j];
                if (sum > 0)
                    --k;
                else if (sum < 0)
                    ++j;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
        }
        return ans;
    }
};