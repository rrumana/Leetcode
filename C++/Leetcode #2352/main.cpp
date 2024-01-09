#include <iostream>     // std::cout
#include <vector>       // std::vector

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        return 1;
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