#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string b2s(uint32_t i) {
    string s {""};
    while (i) {
        if (i%2) {
            //o
            s = "1"s + s;
        } else {
            //e
            s = "0"s + s;
        }
        i/=2;
    }
    return s;
}

// 0.75

//7 * 10-1 + 5 * 10-2 
string d2s(double d) {
    string s{"."};
    int p = -1;
    while (d > 0.0) {
        if (pow(2,p) <= d) {
            s += "1"s;
            d -= pow(2,p);
        } else {
            s += "0"s;
        }
        p -= 1;
    }
    return s; 
}

int main() {
    cout << "32: " << b2s(32) << endl;
    cout << "31: " << b2s(31) << endl;
    cout << "10: " << b2s(10) << endl;
    cout << "0.75: " << d2s(0.70) << endl;
}
