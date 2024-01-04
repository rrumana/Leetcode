#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <numeric>      // std::accumulate

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

void test1() {
    std::vector<int> nums = {1,7,3,6,5,6};
    int expected = 3;

    Solution solution;
	int output = solution.pivotIndex(nums);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums = {1,2,3};
    int expected = -1;

    Solution solution;
	int output = solution.pivotIndex(nums);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> nums = {2,1,-1};
    int expected = 0;

    Solution solution;
	int output = solution.pivotIndex(nums);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}