// Source : https://leetcode.com/problems/spiral-matrix/
// Date   : 03-10-2026

/* Q 54. Spiral Matrix (medium)
Given an m x n matrix, return all elements of the matrix in spiral order.

Example:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5] */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();
        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol)
        {
            // Traverse Top Row (Left to Right)
            for (int i = scol; i <= ecol; ++i)
            {
                ans.push_back(matrix[srow][i]);
            }
            ++srow;

            // Traverse Right Column (Top to Bottom)
            for (int i = srow; i <= erow; ++i)
            {
                ans.push_back(matrix[i][ecol]);
            }
            --ecol;

            // Traverse Bottom Row (Right to Left)
            if (srow <= erow)
            {
                for (int i = ecol; i >= scol; --i)
                {
                    ans.push_back(matrix[erow][i]);
                }
                --erow;
            }

            // Traverse Left Column (Bottom to Top)
            if (scol <= ecol)
            {
                for (int i = erow; i >= srow; --i)
                {
                    ans.push_back(matrix[i][scol]);
                }
                ++scol;
            }
        }
        return ans;
    }
};