#include <iostream>
#include <array>

using namespace std;

class MajorityVote {
public:
    template<size_t SIZE>
    static int getMajority(array<int, SIZE> ary) {
        int value = 0;
        int count = 0;
        for (const int item : ary) {
            if (count == 0) {
                value = item;
                count++;
            } else {
                item == value ? count++ : count--;
            }
        }
        for (const int item : ary) {
            if (item == value) {
                count++;
            }
        }
        return count > SIZE / 2 ? value : -1;
    }
};

int main() {
    const int SIZE = 10;
    array<int, SIZE> ary({1,2,1,1,1,4,5,1,3,1});
    cout << MajorityVote::getMajority(ary) << endl;

    return 0;
}