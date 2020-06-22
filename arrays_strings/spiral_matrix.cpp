#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>>& m) {
	for (const auto& r : m) {
		std::cout << "[";
		for (const auto& e : r) {
			std::cout << " " << e;
		}
		std::cout << " ]\n";
	}
}

void print_spiral_matrix(vector<vector<int>>&& m) {
	print_matrix(m);	
	if (m.empty()) { 
		cout << "Empty matrix\n";		
		return;
	}
	int sx = 0, sy = 0;
	int total_prints = m.size() * m[0].size();
	int rlim = m[0].size();
	int dlim = m.size();
	int ulim = -1;
	int llim = -1;	
	int cx = 0, cy = 1;
	while (total_prints > 0) {
		std::cout << "(" << sx << "," << sy<< "): " << m[sx][sy] << std::endl;	
		// update
		int tx = sx + cx;
		int ty = sy + cy;

		if (ty >= rlim) {
			cx = 1;
			cy = 0;
			// update limits
			ulim += 1;
		} else if (tx >= dlim) {
			cx = 0;
			cy = -1;
			rlim -= 1;
		} else if (ty <= llim) {
			cy = 0;
			cx = -1;
			dlim -= 1;
		} else if (tx <= ulim) {
			cx = 0;
			cy = 1;	
			llim += 1;
		}
			
		sx = sx + cx;
		sy = sy + cy;
		total_prints -= 1;
	}
}

int main() {
	//vector<vector<int>> m1 = {{1,2},{3,4}};
	print_spiral_matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
	print_spiral_matrix({{1, 2, 3}, {4, 5, 6}});
	print_spiral_matrix({{1, 2}, {3,4}, {5, 6}});
	print_spiral_matrix({{1}, {2}, {3}});
	
	//print_spiral_matrix(std::move(m1));
}
