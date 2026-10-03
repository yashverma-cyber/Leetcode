// Source : https://leetcode.com/problems/sort-colors/
// Date   : 03-10-2026

/* Q.75 Sort Colors
You are given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Explanation: The array has two 0s, two 1s, and two 2s.
Sorting them in-place places all 0s first, then all 1s, then all 2s.*/

class Solution
{

    /* Approach : Dutch National Flag Algorithm
    This is a three-way partitioning algorithm that divides the array into three parts:
    * Divide into low, mid and high pointers.
    move mid, if mid == 0 , swap mid and low, increment both mid and low (put in left side)
    if mid == 1, increment mid  (keep 1 in middle)
    and if mid == 2, swap mid and high, decrement high. (put all 2s in right side)
    */

public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = size(nums) - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            }
            else if (nums[mid] == 1)
                ++mid;
            else
            {
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};