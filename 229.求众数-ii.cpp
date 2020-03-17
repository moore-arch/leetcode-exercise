/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (41.78%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 19.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: [3]
 * 
 * 示例 2:
 * 
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstValue;
        int secondValue;
        int firstCount = 0;
        int secondCount = 0;
        for (const int item : nums) {
            if (item == firstValue) {
                ++firstCount;
            } else if(item == secondValue) {
                ++secondCount;
            } else if(firstCount == 0) {
                firstValue = item;
                firstCount = 1;
            } else if(secondCount == 0) {
                secondValue = item;
                secondCount = 1;
            } else {
                --firstCount;
                --secondCount;
            }
        }

        firstCount = 0;
        secondCount = 0;
        for (const int item : nums) {
            if (item == firstValue) {
                firstCount++;
            } else if (item == secondValue) {
                secondCount++;
            }
        }

        vector<int> result;
        if (firstCount > nums.size() / 3) {
            result.push_back(firstValue);
        }
        if (secondCount > nums.size() / 3) {
            result.push_back(secondValue);
        }

        return result;
    }
};
// @lc code=end

