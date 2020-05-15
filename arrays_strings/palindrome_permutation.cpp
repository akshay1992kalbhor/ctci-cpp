#include <iostream>
#include <unordered_map>
using namespace std;

bool pp(string s) {
    if (s.size() <= 1) {
        return true;
    }

    bool odd_seen = false;
    unordered_map<char,int> m;

    for (auto& c : s) {
        if (m.find(c) != m.end()) {
            m[c] += 1;
        } else {
            m[c] = 1;
        }
    }

    for (auto& p : m) {
        if (p.second % 2) {
            if (!odd_seen) {
                odd_seen = true;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    bool ans = pp("AbcAc");
    cout << ans << endl;
}
