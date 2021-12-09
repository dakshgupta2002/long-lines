
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        for (int i = 0; i < matrix.size(); i++)
        {

            //find in this row, the closest to the target
            int hi2 = matrix[i].size() - 1, lo2 = 0;
            while (hi2 >= lo2)
            {
                int mid2 = hi2 - (hi2 - lo2) / 2;

                if (matrix[i][mid2] == target)
                    return true;

                if (matrix[i][mid2] < target)
                {
                    lo2 = mid2 + 1;
                }
                else
                {
                    hi2 = mid2 - 1;
                }
            }
        }

        return false;
    }
};

//optimised 2 pointer approach
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0, col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};