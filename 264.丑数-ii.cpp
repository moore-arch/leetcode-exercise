/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (47.73%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 23K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
#include <bitset>
#include <vector>
#include <array>
using namespace std;

class Solution {
private:
    static const int SIZE = 65000;
    array<bitset<INT16_MAX>, SIZE> *ary;

public:
    Solution() : ary(new array<bitset<INT16_MAX>, SIZE>) {
        ary->at(0).set(1, 1);
        ary->at(0).set(2, 1);
        ary->at(0).set(3, 1);
        ary->at(0).set(4, 1);
        ary->at(0).set(5, 1);
        ary->at(0).set(6, 1);
    }
    
private:
    // bool checkAndSet(const int index, const int base) {
    //     int arrayIndex = (index / base) / INT16_MAX;
    //     int bitsetIndex = (index / base) % INT16_MAX;
    //     if (ary->at(arrayIndex).test(bitsetIndex)) {
    //         ary->at(index / INT16_MAX).set(index % INT16_MAX, 1);
    //         cout << arrayIndex << ", " << bitsetIndex << endl;
    //         return true;
    //     }
    //     return false;
    // }

    bool isUglyNumber(const int index) {
        int arrayIndex = index / INT16_MAX;
        int bitsetIndex = index % INT16_MAX;
        return ary->at(arrayIndex).test(bitsetIndex);
    }

    void setBit(const int index) {
        int arrayIndex = index / INT16_MAX;
        int bitsetIndex = index % INT16_MAX;
        ary->at(arrayIndex).set(bitsetIndex);
    }

public:
    array<int, 1700> uglyNUmber = {1, 2, 3, 4, 5, 6};

    int nthUglyNumber(int n) {
        for (int i = 0; i < n; i++) {
            
        }
    }
    // int nthUglyNumber(int n) {
    //     if (n <= 6) {
    //         return n;
    //     }
    //     int cnt = 6;
    //     int number = 6;
    //     while (cnt < n) {
    //         number += 1;
    //         if ((number % 5 == 0) && isUglyNumber(number / 5)) {
    //             setBit(number);
    //             cnt += 1;
    //         } else if ((number % 3 == 0) && isUglyNumber(number / 3)) {
    //             setBit(number);
    //             cnt += 1;
    //         } else if (((number & 0x1) == 0) && isUglyNumber(number / 2)) {
    //             setBit(number);
    //             cnt += 1;
    //         }
    //     }
    //     return number;
    // }
};
// @lc code=end

