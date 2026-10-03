# Kadane’s Algorithm (Maximum Subarray / Product)  

## The Analogy: Carrying a Backpack of Debts & Profits  
You are walking down a street collecting money (numbers).   
Some houses give you profit (+), some give you debt (-).  
As you walk, you keep a running total (sum).  
At every house, you ask yourself:   
"Is my total debt from the past dragging me down so much that I'm better off throwing away my bag,  
starting completely fresh with just this house's money?"  

In code: sum = max(num, sum + num) handles this.   
If sum + num drops lower than the current house's value (num),  
 you drop the past baggage and start fresh right there.  

## Implementation --> [[click here]](../Arrays/Maximum%20Subarray.cpp)
  
### Q. Given an integer array nums, find the subarray with the largest sum, and return its sum.  

e.g. -->   
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]    
Output: 6    
Explanation: The subarray [4,-1,2,1] has the largest sum 6. 

```
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;

        for(const int num : nums) {
            
            sum = max(num, sum+num);
            ans = max(sum, ans);
        }
        return ans;
    }
``` 
