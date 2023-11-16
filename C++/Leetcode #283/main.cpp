#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int i = 0;
        std::vector<int>::iterator it = nums.begin();
        while(i < nums.size()){
            if(*it == 0){
                nums.erase(it);
                nums.push_back(0);
            } else {
                it++;
            }
            i++;
        }
    }
};

void test1() {
    std::vector nums = {0,1,0,3,12};
    std::vector expected = {1,3,12,0,0};

    Solution solution;
	solution.moveZeroes(nums);

    if(nums == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector nums = {0};
    std::vector expected = {0};

    Solution solution;
	solution.moveZeroes(nums);

    if(nums == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}