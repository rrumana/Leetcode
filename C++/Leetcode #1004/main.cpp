#include <iostream>     // std::cout
#include <algorithm>    // std::max / std::min
#include <vector>       // std::vector

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maximum = 0, i = 0,  j = height.size()-1;
        while(i < j){
            maximum = std::max(maximum, (j-i)*std::min(height[i], height[j]));
            if(height[i] > height[j]) j--;
            else i++;
        }
        return maximum;
    }
};

void test1() {
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int expected = 49;

    Solution solution;
	int output = solution.maxArea(nums);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums = {1,1};
    int expected = 1;

    Solution solution;
	int output = solution.maxArea(nums);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> nums = {2,3,4,5,18,17,6};
    int expected = 16;

    Solution solution;
	int output = solution.maxArea(nums);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}