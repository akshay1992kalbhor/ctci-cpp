#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


bool route_bet_nodes(unordered_map<int, vector<int>> m, int src, int dst) {
    queue<int> q;
    unordered_map<int,bool> v;
    q.push(src);
    v[src] = true;
    // n nodes
    // 2 * (n - 1) edges
    while (!q.empty()) {
        const int& cnode = q.front();
        for ( auto& n : m[cnode]) {
            // if dst is found return true;
            if (n == dst) {
                return true;
            }
            // if not seen add to queue;
            if (v.find(n) == v.end()) {
                q.push(n);
                v[n] = true;
            }
        }
        q.pop();
    }
    return false;
}

int main() {

    
    unordered_map<int, vector<int>> m {{1, {2}}, {2, {3}}, {3, {}}};
    cout << route_bet_nodes(m, 1, 2) << endl;
    cout << route_bet_nodes(m, 1, 3) << endl;
    cout << route_bet_nodes(m, 2, 1) << endl;
}       
