#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;


int search_rotated_array(vector<int>& vec, int target, int lo, int hi) {
	
	if (lo > hi) { return -1; }
	
	int mid = ( lo + hi ) / 2;
	
	if (vec[mid] == target) {
		return mid;
	} else {
		if (vec[lo] < vec[mid]) {
			// changing the first condition to (target <= vec[mid]) should not matter, because the case where target == vec[mid] would be handled in the if clause
			// (corresponding to the outermost else).
			if (target < vec[mid] && target >= vec[lo]) {
				return search_rotated_array(vec, target, lo, mid-1);
			} else {
				return search_rotated_array(vec, target, mid+1, hi);
			}	
		} else if (vec[lo] > vec[mid]) {
			if (target > vec[mid] && target <= vec[hi]) {
				return search_rotated_array(vec, target, mid+1, hi);
			} else {
				return search_rotated_array(vec, target, lo, mid-1);
			}	
		} else {
			// problem case: vec[low] == vec[mid]
			if (vec[hi] != vec[mid]) {
				// left is impossible, because there cannot be two inflection points (high to low)
				return search_rotated_array(vec, target, mid+1, hi);
			} else {
				int left = search_rotated_array(vec, target, lo, mid-1);
				if (left == -1) {
					return search_rotated_array(vec, target, mid+1, hi);
				} else {
					return left;
				}
			}
		} 	
	}
}


int main(int argc, char** argv) {
	// x -1 1 16
	vector<int> in {2,4,2,2,2};
	int target = std::atoi(argv[1]);
	int ans = search_rotated_array(in, target, 0, in.size()-1);
	cout << ans << endl;
}
