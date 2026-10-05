// Source : https://leetcode.com/problems/two-sum/
// Date   : 05-10-2026

/* Q1. Two Sum (Easy)
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. */

class Solution
{
    /* Approach: Use a hash map to store the elements and their indices.
    For each element, calculate the complement (target - element)
    and check if it exists in the hash map.
    If it does, return the indices of the two elements. */

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> mpp;
        for (int i = 0; i < size(nums); i++)
        {
            int left = target - nums[i];
            if (mpp.count(left))
            {
                return {mpp[left], i};
            }
            else
                mpp[nums[i]] = i; // The Trick to Remember
                                  // A hash map allows you to search instantly by KEY.
                                  // Because we want to instantly search by the number/complement, the number MUST be the KEY:
        }
        return {};
    }
};