#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate_matrix(vector<vector<int>> v) {
    if (v.empty()) {
	return v;
    }

    int size = v.size();
    int sr = 0;
    int sc = 0;
    while (size >= 2) {
	
	for (int col = 0; col < size-1; col++) {
	    int start = v[sr][sc+col];
	    // done
	    vector<int> rows = {sr+col,        sr+size-1,     sr+size-1-col, sr};
	    vector<int> cols = {sc+size-1, sc+size-1-col, sc, sc+col};
	    for (int n = 0; n < 4; n++) {
		int temp = v[rows[n]][cols[n]];
		v[rows[n]][cols[n]] = start;
		start = temp;
		cout << rows[n] << "," << cols[n] << endl;	
	    } 
	    
	}
	cout << "FIRST" << endl;
	size -= 2;
	sr += 1;
	sc += 1;
    }
    return v;
}

int main() {
    vector<vector<int>> v {{1, 2, 3, 4},{ 5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    auto ans = rotate_matrix(v);
    for (auto v : ans) {
	for (auto i : v) {
	    cout << i << endl;
	}
    }
}
