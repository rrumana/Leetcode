#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1, cnt = 0;
        std::sort(nums.begin(), nums.end());
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                i++;
                j--;
                cnt++;
            } else if (nums[i] + nums[j] < k) {
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }
};

void test1() {
    std::vector<int> nums = {1,2,3,4};
    int k = 5;
    int expected = 2;

    Solution solution;
	int output = solution.maxOperations(nums, k);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums = {3,1,3,4,3};
    int k = 6;
    int expected = 1;

    Solution solution;
	int output = solution.maxOperations(nums, k);

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