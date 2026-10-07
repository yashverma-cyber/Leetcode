// Source : https://leetcode.com/problems/longest-consecutive-sequence/
// Date   : 07-10-2026

/*128. Longest Consecutive Sequence (Medium)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sq;
        int n = size(nums);
        for(const int n : nums) 
            sq.insert(n);
        int longest = 0;
        for(auto it : sq) {
            if(sq.find(it-1) == sq.end()) {
                /* Assuming that [4, 3, 1, 2] if we have 4. then 3 exists or not, 
                then going to start and starting , for faster complexity*/
                int cnt = 1; 
                int x = it;
                while(sq.find(x+1) != sq.end()) { 
                    ++cnt;
                    ++x;
                }
                longest = max(cnt, longest);
            }
        }
        return longest;
    }
};

