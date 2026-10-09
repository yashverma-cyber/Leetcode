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
    // STL Approach in ../Misc/(M) Find First and Last Position of Element in Sorted Array.cpp
private:
    // Implementing lower_bound from scratch
    int lowerBound(const vector<int> &nums, int target)
    {
        int low = 0, high = (int)nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                ans = mid; // Potential answer found, try looking further left
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // Too small, look to the right
            }
        }
        return ans;
    }

    // Implementing upper_bound from scratch
    int upperBound(const vector<int> &nums, int target)
    {
        int low = 0, high = (int)nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                ans = mid; // Potential answer found, try looking further left
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // Too small or equal, look to the right
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = lowerBound(nums, target);

        // Check if 'l' is out of bounds or if the element doesn't match the target
        if (l == nums.size() || nums[l] != target)
        {
            return {-1, -1};
        }

        // upper_bound gives the index *after* the last occurrence, so we subtract 1
        int r = upperBound(nums, target) - 1;

        return {l, r};
    }
};