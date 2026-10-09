// Source : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Date : 09-10-2026

/* Q 34. Find First and Last Position of Element in Sorted Array (medium)
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4] */

class Solution
{
    /* Approach : STL
    Binary Search Approach in ../Searching/(E) Binary Search.cpp */
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        const int l = ranges::lower_bound(nums, target) - nums.begin();
        // performs a binary search to find the first position where an element is greater than or equal to target.

        if (l == size(nums) || nums[l] != target)
            return {-1, -1};
        const int r = ranges::upper_bound(nums, target) - nums.begin() - 1;
        // performs a binary search to find the first position where an element is strictly greater than target

        return {l, r};
    }
};