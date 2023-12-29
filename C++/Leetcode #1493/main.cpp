#include <iostream>     // std::cout
#include <vector>       // std::vector

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        return 0;
    }
};

void test1() {
    std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int expected = 6;

    Solution solution;
	int output = solution.longestOnes(nums, k);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    int expected = 10;

    Solution solution;
	int output = solution.longestOnes(nums, k);

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