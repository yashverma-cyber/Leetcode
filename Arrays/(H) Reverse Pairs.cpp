// Source : https://leetcode.com/problems/reverse-pairs/
// Date   : 05-10-2026

/* Q 493. Reverse Pairs (Hard)
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1 */

class Solution
{

    /* Approach : Using Merge Sort
       using that, whenever condition of
       * 0 <= i < j < nums.length and
       * nums[i] > 2 * nums[j]
       comes, count it to count */

    int merge(vector<int> &arr, int st, int mid, int end)
    {
        vector<int> temp;
        int i = st, j = mid + 1;
        int cnt = 0;
        for (int idx = st; idx <= mid; idx++)
        {
            while (j <= end && (long long)arr[idx] > 2LL * arr[j])
                ++j;
            cnt += j - (mid + 1);
        }

        j = mid + 1;
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
        for (int k = st; k <= end; k++)
        {
            arr[k] = temp[k - st];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int st, int end)
    {
        int cnt = 0;
        if (st < end)
        {
            int mid = st + (end - st) / 2;
            cnt += mergeSort(arr, st, mid);
            cnt += mergeSort(arr, mid + 1, end);
            cnt += merge(arr, st, mid, end);
            return cnt;
        }
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, size(nums) - 1);
    }
};