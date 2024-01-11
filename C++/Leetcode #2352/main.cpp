#include <iostream>         // std::cout
#include <vector>           // std::vector
#include <map>              // std::map

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::map<std::vector<int>, int> rows;
        std::map<std::vector<int>, int> cols;
        int width = grid[0].size();
        int height = grid.size();
        int colisions = 0;

        // make rows map
        for(auto row : grid){
            if(rows.find(row) == rows.end()) rows[row] = 1;
            else rows[row] = rows[row] + 1;
        }

        // handle cols
        for(int i = 0; i < width; i++) {
            std::vector<int> col;
            for(int j = 0; j < height; j++){
                col.push_back(grid[j][i]);
            }
            if(cols.find(col) == cols.end()) cols[col] = 1;
            else cols[col] = cols[col] + 1;
        }

        for(auto row = rows.begin(); row != rows.end(); ++row){
            for(auto col = cols.begin(); col != cols.end(); ++col){
                if(row->first != col->first) continue;
                colisions += row->second * col->second;
            }
        }

        return colisions;
    }
};

void test1() {
    std::vector<std::vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    int expected = 1;

    Solution solution;
	int output = solution.equalPairs(grid);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<std::vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    int expected = 3;

    Solution solution;
	int output = solution.equalPairs(grid);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {}

int main() {
    test1();
    test2();
    //test3();
	return 0;
}