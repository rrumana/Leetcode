#include <iostream>
#include <vector> 

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int index = 0;
        int i = 2;
        while(i < nums.size()){
            if(nums[i] == nums[index]){
                if(i-index < 2){
                    i++;
                } else {
                    nums.erase(nums.begin()+i);
                }
            } else {
                index++;
            }
        }
        return nums.size();
    }
};

void test1() {
    std::vector<int> nums{1,1,1,2,2,3};
    std::vector<int> expectedArray{1,1,2,2,3};

    Solution solution;
    int ans = solution.removeDuplicates(nums);
    nums.erase(nums.begin()+ans,nums.end());

    if(ans == expectedArray.size() && nums == expectedArray) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums{0,0,1,1,1,1,2,3,3};
    std::vector<int> expectedArray{0,0,1,1,2,3,3};

    Solution solution;
    int ans = solution.removeDuplicates(nums);
    nums.erase(nums.begin()+ans,nums.end());

    if(ans == expectedArray.size() && nums == expectedArray) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}