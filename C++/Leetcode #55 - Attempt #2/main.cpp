#include <iostream>
#include <vector>
#include <list>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;
        maxReach = std::max(maxReach, i + nums[i]);
    }
        return true;
    }
};

void test1() {
    std::vector<int> input = {2,3,1,1,4};
    bool output = false;
    bool expected = true;

    Solution solution;
	output = solution.canJump(input);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> input = {3,2,1,0,4};
    bool output = false;
    bool expected = false;

    Solution solution;
	output = solution.canJump(input);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}
