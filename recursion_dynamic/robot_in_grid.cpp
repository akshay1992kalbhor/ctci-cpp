#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <unordered_set>
#include <functional>
using namespace std;



struct Cell {
    int row;
    int col;
    Cell(int r, int c) : row{r}, col{c} {}
};

bool operator==(const Cell& lhs, const Cell& rhs) {
    return lhs.row == rhs.row && lhs.col == rhs.col;
}

struct CellHash {
    size_t operator()(const Cell& c) const {
        return hash<int>()(c.row) ^ hash<int>()(c.col);
    }
};

bool robot_grid(int rows, int cols, vector<vector<int>>& grid) {
        stack<Cell> s;
        s.push({0, 0});
        unordered_set<Cell, CellHash> seen;
        seen.insert({0,0});
        while (!s.empty()) {
            Cell c = s.top();
            s.pop();

            if (c.row ==  rows-1 && c.col == cols-1) {
                return true;
            }

            // check right
            if (c.col < cols - 1) {
                if ((seen.find({c.row, c.col+1}) == seen.end()) && grid[c.row][c.col+1] == 1) {
                    s.push({c.row, c.col+1});
                    seen.insert({c.row, c.col+1});
                }
            }
            // check bottom
            if (c.row < rows - 1) {
                if ((seen.find({c.row+1, c.col}) == seen.end()) && grid[c.row+1][c.col] == 1) {
                    s.push({c.row+1, c.col});
                    seen.insert({c.row+1, c.col});
                }
            }

        }
        return false;
}

int main() {
    
    vector<vector<int>> grid {
                                {1, 1, 1},
                                {0, 0, 0},
                                {1, 1, 1}};

    
    bool b = robot_grid(3, 3, grid);
    cout << b << endl;

}
