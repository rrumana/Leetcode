#include <iostream>
#include <vector> 

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int ans = 0;
        for(int i=0; i<nums.size();  i++){
            if(nums[i] != val){
                nums[ans] = nums[i];
                ans += 1; 
            }
        }
        return ans;
    }
};

void test1() {
    std::vector<int> nums{3,2,2,3};
    int val = 3;
    int expected = 2;

    Solution solution;

    if(solution.removeElement(nums, val) == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;
    int expected = 5;

    Solution solution;

    if(solution.removeElement(nums, val) == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}