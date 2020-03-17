/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.36%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    84.7K
 * Total Submissions: 139.7K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = 0;
        int cnt = 0;
        for (const int item : nums) {
            if (cnt == 0) {
                value = item;
                cnt = 1;
            } else if (item == value) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return value;
    }
};
// @lc code=end

