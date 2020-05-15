#include <iostream>
#include <vector>




using namespace std;


// n : a
// 0 : 1 ; []
// 1 : 1 ; [1]
// 2 : 2 ; [1,1], [2]
// 3 : 4 ; [1,1,1], [1,2], [2, 1], [3]


int triple_step(int nsteps) {
    vector<int> v {1, 1, 2};
    if (nsteps <= 2)
        return v[nsteps];

    // add to v
    // // nsteps = 3 ; loop once, if 4 loop twice, so loop (nsteps-2) times
    for (int i = 3; i <= nsteps; i++)
        v.push_back(v[i-3] + v[i-2] + v[i-1]);
    return v[nsteps];
}

int main() {
    cout << triple_step(3) << endl;
    cout << sizeof(int64_t) << endl;
}
