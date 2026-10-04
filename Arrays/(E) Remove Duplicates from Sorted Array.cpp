// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Date   : 01-10-2026

/* Q) 26. Remove Duplicates from Sorted Array (Easy)
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​.
After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order.
The remaining elements beyond index k - 1 can be ignored.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the
first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k
(hence they are underscores).*/

class Solution
{

    /* Approach: Since we know its sorted and no duplicates,
    so checking if the current element is first element ,
    if not then checking if it's greater than the previous element
    then only add it to the array */
    // Time Complexity : O(n)

public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (const int num : nums)
        {
            if (i < 1 || num > nums[i - 1])
                nums[i++] = num;
        }
        return i;
    }
};