// Source : https://leetcode.com/problems/trapping-rain-water/
// Date   : 04-10-2026

/* 42. Trapping Rain Water (hard)
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
6 units of rain water (blue section) are being trapped.*/

class Solution
{

    /* Approach : Two Pointers
    Use two pointers, one at the beginning and one at the end of the array.
    Keep track of the maximum height seen so far from both sides.
    Move the pointer with the smaller height towards the other pointer.
    Add the difference between the current height and the maximum height seen so far to the result.
    */

public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int l = 0, r = size(height) - 1;
        int lmax = 0, rmax = 0;
        while (l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax)
            {
                ans += lmax - height[l];
                ++l;
            }
            else
            {
                ans += rmax - height[r];
                --r;
            }
        }
        return ans;
    }
};
