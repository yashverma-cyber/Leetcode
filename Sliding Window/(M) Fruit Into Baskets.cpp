// Source : https://leetcode.com/problems/fruit-into-baskets/
// Date : 08-10-2026

/* Q 904. Fruit Into Baskets (medium)
You are visiting a farm that has a single row of fruit trees arranged from left to right.
The trees are represented by an integer array fruits
where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible.
However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree)
while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].*/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0;
        unordered_map<int, int> count;
        int ans = 0;
        while (r < size(fruits))
        {
            count[fruits[r]]++;
            while (size(count) > 2)
            {
                if (--count[fruits[l]] == 0)
                    count.erase(fruits[l]);
                ++l;
            }
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};