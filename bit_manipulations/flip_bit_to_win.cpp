#include <iostream>
using namespace std;


// 1775 => 11011101111
int flipbit(uint32_t input) {

    if (!input) {
        return 1;
    }

    int maxseen = 0;
    int first = 0;
    int second = 0;
    while (input) {
        if (!(input%2)) {
            // even
            int maybemax = first + second + 1;
            if (maxseen < maybemax) {
                cout << maybemax << endl;
                maxseen = maybemax;
            }
            first = second;
            second = 0;
        } else {
            // odd
            second += 1;
        }
        input /= 2;
    }
    if (!maxseen) {
        return second;
    } else {
        if (first + second + 1 > maxseen) {
            return first + second + 1;
        } else {
            return maxseen;
        }
    }
}

int main() {
    cout << flipbit(30) << endl;
}
