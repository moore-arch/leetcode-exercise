/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 137.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
class Solution {
private:

    void resetLand(int c, int r, vector<vector<char>>& grid) {
        if (c < 0 || c >= grid.size() || r < 0 || r >= grid[0].size()) {
            return ;
        }

        if (grid[c][r] == '1') {
            grid[c][r] = 0;
            resetLand(c - 1, r, grid);
            resetLand(c + 1, r, grid);
            resetLand(c, r - 1, grid);
            resetLand(c, r + 1, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    resetLand(i, j, grid);
                    cnt += 1;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

