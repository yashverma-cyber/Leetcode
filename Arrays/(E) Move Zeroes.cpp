// Source : https://leetcode.com/problems/move-zeroes/
// Author : Yash Verma
// Date   : 01-10-2026

/* Q) 283. Move Zeroes (Easy)

Given an integer array nums, move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Note: that you must do this in-place
without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0] */

class Solution
{

    /* Approach : Fill all the non-zero elements at the beginning of the array
        and then fill the remaining positions with zeros. */
public:
    void moveZeroes(vector<int> &nums)
    {

        int inpos = 0;
        for (int i = 0; i < size(nums); i++)
        {
            if (nums[i] != 0)
            {
                nums[inpos] = nums[i];
                inpos++;
            }
        }
        while (inpos < size(nums))
        {
            nums[inpos] = 0;
            inpos++;
        }
    }
};
