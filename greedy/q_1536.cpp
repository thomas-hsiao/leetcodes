/*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 

Example 1:

Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0

 

Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 200
    grid[i][j] is either 0 or 1

*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> rowZeros(n);

        // 1. 預處理：計算每一列從右側開始連續 0 的數量
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) ++count;
                else break;
            }
            rowZeros[i] = count;
        }

        int totalSwaps = 0;

        // 2. 貪婪策略：為每一行找到符合條件的列
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i; // 這一行至少需要這麼多個 0
            int found = -1;

            // 在剩下的列中尋找第一個符合條件的
            for (int j = i; j < n; ++j) {
                if (rowZeros[j] >= target) {
                    found = j;
                    break;
                }
            }

            // 找不到符合要求的列，直接回傳 -1
            if (found == -1) return -1;

            // 3. 模擬交換過程：將第 found 列一路換回第 i 列
            for (int k = found; k > i; --k) {
                std::swap(rowZeros[k], rowZeros[k - 1]);
                ++totalSwaps;
            }
        }

        return totalSwaps;
    }
};