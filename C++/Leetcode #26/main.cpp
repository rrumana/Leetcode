#include <iostream>
#include <vector> 

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[index]){
                nums[index+1] = nums[i];
                index = index+1;
            }
        }
        return index+1;
    }
};

void test1() {
    std::vector<int> nums{1,1,2};
    std::vector<int> expectedArray{1,2};

    Solution solution;
    int ans = solution.removeDuplicates(nums);
    nums.erase(nums.begin()+ans,nums.end());

    if(ans == expectedArray.size() && nums == expectedArray) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    std::vector<int> expectedArray{0,1,2,3,4};

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