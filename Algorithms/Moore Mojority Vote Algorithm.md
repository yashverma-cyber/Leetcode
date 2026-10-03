# Boyer-Moore Voting Algorithm  
## Problem Example: Majority Element (LeetCode 169)
    Time Complexity: O(n)
    Space Complexity: O(1)

## How it Works ?
Think of this like a political election where each number is a candidate:  
* ans tracks the current candidate winning the vote, and count tracks their lead.  
* If count hits 0, it means previous candidates have canceled each other out,     
    so we pick a new candidate (ans = num).  
* When we see our candidate again, we add +1 to count.   
* When we see a different number, we subtract -1.  
Because the majority element appears more than half the time (floor(n/2)),   
it is mathematically guaranteed to survive the cancellations and remain as ans at the end.  
  
## Implementation -> [click here](../Arrays/Majority Element.cpp)

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int count = 0;
        for (const int num : nums) {
            if (count == 0)
                ans = num;
            count += num == ans ? 1 : -1;
        }
        return ans;
    }
};
```
e.g. -> Input: nums = [2,2,1,1,1,2,2]
        Output: 2
