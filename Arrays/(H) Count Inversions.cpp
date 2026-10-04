// Source : https://takeuforward.org/practice/dsa/count-inversions
// Date   : 03-10-2026

/* **Program is not in Leetcode, but solving in takeuforward.com** */
/* Q 131. Count Inversions (Hard)
Given an integer array nums. Return the number of inversions in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.

Example 1:
Input: nums = [2, 3, 7, 1, 3, 5]
Output: 5
Explanation:
The responsible indexes are:
nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5 */

class Solution
{
    /* Approach -> Merge Sort, and then in pairs,
    check if right pair is less than left if yes,
    then add the number of elements left in the left pair to the count of inversions.
    */

    long long merge(vector<int> &arr, int st, int mid, int end)
    {
        vector<int> temp;
        int i = st, j = mid + 1;
        long long cnt = 0;
        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                ++i;
            }
            else
            {
                temp.push_back(arr[j]);
                ++j;
                cnt += mid - i + 1;
            }
        }
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            ++i;
        }
        while (j <= end)
        {
            temp.push_back(arr[j]);
            ++j;
        }

        for (int idx = 0; idx < size(temp); ++idx)
        {
            arr[st + idx] = temp[idx];
        }
        return cnt;
    }

    long long mergeSort(vector<int> &arr, int st, int end)
    {
        long long cnt = 0;
        if (st >= end)
            return cnt;
        int mid = st + (end - st) / 2;
        cnt += mergeSort(arr, st, mid);
        cnt += mergeSort(arr, mid + 1, end);
        cnt += merge(arr, st, mid, end);

        return cnt;
    }

public:
    long long int numberOfInversions(vector<int> nums)
    {
        return mergeSort(nums, 0, size(nums) - 1);
    }
};