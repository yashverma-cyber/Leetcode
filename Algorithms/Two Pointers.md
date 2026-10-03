# Two Pointers Technique  
Time Complexity: O(n)
Space Complexity: O(1)

## The Analogy: 
Two People Inspecting a Long Line from Both Ends
Imagine a word written on a long strip of paper.
You want to check if it's the same forwards and backwards (palindrome).

* You put Friend A at the very beginning and Friend B at the very end.
* They walk toward each other. 
* Once both are looking at actual letters, they shout out what they see to check if they match.
* If they do, they keep walking inward until they meet in the middle.

## Implementation -> [click here](../Arrays/Valid%20Palindrome.cpp)

Q. A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers. 
Given a string s, return true if it is a palindrome, or false otherwise.

Example:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

```
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = size(s)-1;
        
        while(l < r) {
            while(l < r && !isalnum(s[l])) 
                ++l;
            while(l < r && !isalnum(s[r])) 
                --r;
            if(tolower(s[l]) != tolower(s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
```





