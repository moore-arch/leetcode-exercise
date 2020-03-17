#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

#include "264.丑数-ii.cpp"

using namespace std;

class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i2=0,i3=0,i5=0,i=1;
        while(i++<n) {
            int tmp=min(2*res[i2],min(3*res[i3],5*res[i5]));
            res.push_back(tmp);
            if(tmp==2*res[i2]) i2++;
            if(tmp==3*res[i3]) i3++;
            if(tmp==5*res[i5]) i5++;
        }
        return res.back();
    }
};


int main() {
    Solution solution;
    Solution2 solution2;
    solution2.nthUglyNumber(1690);
    // for (int i = 1; i < 1000; i++) {
    //     if (solution.nthUglyNumber(i) != solution2.nthUglyNumber(i)) {
    //         cout << i << ", " << false << endl;
    //     }
    // }
    cout << solution.nthUglyNumber(1690) << endl;
    return 0;
}