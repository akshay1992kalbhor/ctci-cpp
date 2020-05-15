#include <iostream>
#include <vector>

using namespace std;



void zero_matrix(vector<vector<int>>& mat){
    if (mat.empty()) {
        return;
    }
    bool fr, fc = false;
    // check frow
    for (auto& i : mat[0]) {
        if (i == 0) {
	    fr = true;
	}
    }
    // check fcol
    for (int i = 0; i < mat.size(); i++) {
	if (mat[i][0] == 0) {
	    fc = true;	
	}
    }
    for (int row = 1; row < mat.size(); row++) {
	for (int col = 1; col < mat[0].size(); col++) {
	    if (mat[row][col] == 0) {
		mat[row][0] = 0;
		mat[0][col] = 0;
	    }
	}
    }
    for (int row = 1; row < mat.size(); row++) {
	if (mat[row][0] == 0) {
	    for (auto& i : mat[row]) {
		i = 0;
	    }
	}
    } 
    for (int col = 1; col < mat[0].size(); col++) {
	if (mat[0][col] == 0) {
	   for (int row = 0; row < mat.size(); row++) {
		mat[row][col] = 0;
	   } 
	}
    } 
    if (fr) {
	for (auto& i : mat[0])
	    i = 0;
    }
    if (fc) {
	for (auto& r : mat) {
		r[0] = 0;
	}
    }
}


int main() {
    vector<vector<int>> mat {{1, 2, 3}, {0, 4, 5}, {10, 6, 7}};
    zero_matrix(mat);
    for (auto& r : mat)
	for (auto& i : r)
	    cout << i << endl;

}
