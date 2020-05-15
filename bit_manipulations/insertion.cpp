#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void insertion(uint32_t m, uint32_t n, int i, int j) {
    uint32_t mask = pow(2.0, j-i+1) - 1.0;
    mask = ~(mask << i);
    uint32_t maskedn = n & mask;
    uint32_t shiftedm = m << i;
    cout << (maskedn | shiftedm) << endl;
}

void insertion1(uint32_t m, uint32_t n, int i, int j) {
    uint32_t mask1 = i > 0 ? pow(2.0, i+1) - 1.0 : 0;
    uint32_t mask2 = j < 31 ? ~(uint32_t)(pow(2.0, j+1) - 1.0) : 0;
    uint32_t final_mask = mask1 | mask2;
    uint32_t maskedn = n & final_mask;
    uint32_t shiftedm = m << i;
    cout << (maskedn | shiftedm) << endl;
}
/*
1-1
1111
0010
1101

1101
0001
0001

1101
1000
1000

1001

1001

<= 111101 <= 0000010 <= 2^(diff+1)-1
*/
int main() {
    insertion1(0, 13, 1, 2);
}
