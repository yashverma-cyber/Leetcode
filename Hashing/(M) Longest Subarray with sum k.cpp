//Source : https://takeuforward.org/practice/dsa/longest-subarray-with-sum-k
//Date   : 07-10-2026

/* Q 178. Longest subarray with sum K
Given an array nums of size n and an integer k, 
find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example 1:
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4.
This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
Therefore, the length of this sub-array is 4.*/

class Solution {
    /* Approach Prefix Sum + Hash Map (Works for Negatives, Positives, and Zeros)
    This approach uses running prefix sums.
    If the prefix sum up to index i is prefix_sum, 
    we check if prefix_sum - k has been seen before in our map. 
    If it has, the elements between that previous index and i sum to k.*/
    //Time complexity -> O(n)
    //Space complexity -> O(n)
    
public:
    int longestSubarray(std::vector<int>& nums, int k) {
        std::unordered_map<long long, int> prefixMap;
        long long currentSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];

            // If sum from index 0 to i equals k
            if (currentSum == k) {
                maxLength = i + 1;
            }

            // Check if (currentSum - k) exists in the map
            long long rem = currentSum - k;
            if (prefixMap.find(rem) != prefixMap.end()) {
                int len = i - prefixMap[rem];
                maxLength = std::max(maxLength, len);
            }

            // Store prefixSum in map only if it doesn't already exist
            // (to keep the index as small as possible for maximum length)
            if (prefixMap.find(currentSum) == prefixMap.end()) {
                prefixMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};