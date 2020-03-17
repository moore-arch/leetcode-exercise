/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 *
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (41.09%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 38.8K
 * Testcase Example:  '10\n6'
 *
 * 我们正在玩一个猜数字游戏。 游戏规则如下：
 * 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 * 每次你猜错了，我会告诉你这个数字是大了还是小了。
 * 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
 * 
 * -1 : 我的数字比较小
 * ⁠1 : 我的数字比较大
 * ⁠0 : 恭喜！你猜对了！
 * 
 * 
 * 示例 :
 * 
 * 输入: n = 10, pick = 6
 * 输出: 6
 * 
 */

// @lc code=start
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        unsigned left = 1;
        unsigned right = n;
        unsigned value = left + (right - left) / 2;
        int state = INT_MAX;
        while ((state = guess(value)) != 0) {
            if (state > 0) {
                left = value + 1;
            } else {
                right = value;
            }
            value = left + (right - left) / 2;

            // cout << "state = " << state << ", value = " << value << ", left = " << left << ", right = " << right << endl;
        }

        return value;
    }
};
// @lc code=end

