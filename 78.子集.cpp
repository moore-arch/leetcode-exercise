/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.00%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    45K
 * Total Submissions: 59.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (const int item : nums) {
            const int SIZE = result.size();
            for (int i = 0; i < SIZE; i++) {
                vector<int> vec(result.at(i));
                vec.push_back(item);
                result.push_back(vec);
            }            
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums({1,2,3});
    vector<int> temp(nums);
    // cout << temp.at(0) << endl;
    solution.subsets(nums);

    return 0;
}
