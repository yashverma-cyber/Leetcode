# Spiral Matrix 
  Time Complexity -> O(m*n)
Approach -> s = start, e = end  
* int srow = 0, erow = n - 1;  
* int scol = 0, ecol = m - 1;
* Traverse Top Row (Left to Right) then go to below row by ++srow
* Traverse Right Column (Top to Bottom) then shift end row forward by --erow
* Traverse Bottom Row (Right to Left) then shift ending row up by --erow;
* Traverse Left Column (Bottom to Top) then shift starting column to right by ++scol;

## Q. Given an m x n matrix, return all elements of the matrix in spiral order.  
Example:  
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]  
Output: [1,2,3,6,9,8,7,4,5] 

### Implementation ->  [click here](../Arrays/Spiral%20Matrix.cpp)  

```
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
```
