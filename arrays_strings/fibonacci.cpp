#include <iostream>

using namespace std;
// 0, 1, 1, 2
/* O() : time complexity */
/* O 

f5 => f4 + f3 => f3 + f2 + f2 +f1 => f2 + f1 + f1 + f0 + f1 + f0 
 => 1 + 2 + 4 + 8 + 16
2^n

f10 => 9,8 => 6 => 4 => 2 => 5,0

space complexity: ??
*/
int fibonacci_rec(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}
// 0  1  2  3
// 0, 1, 1, 2, 3, 5
// Space: Constant
// Time: N
int fib_it(int n) {
    // if n = 2; add prev and bef_prev; = loop once
    // if n = 3; loop twice = 2
    // no of loops = n - 1;
    int prev = 1;
    int b_prev = 0;
    if (n <= 1) {
        return n;
    }

    int nloops = n - 1;
    for (int i = 0; i < nloops; i++) {
        int next = b_prev + prev;
        b_prev = prev;
        prev = next;
    }
    return prev;
}




int main() {
    for (int i = 0; i < 10; i++)
        cout << i << ": " << fib_it(i) << endl;
}
