#include <iostream>     // std::cout
#include <vector>       // std::vector

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int count1=0;
        int count2=0;
        int sum=0;
        bool flag = true;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                flag = false;
                break;
            }
        }

        if(flag) return nums.size()-1;

        for(int i=0; i<nums.size(); i++){
            if(i==0 && nums[i]==0 || i==nums.size()-1 && nums[i]==0){
                continue;
            }
            if(count1+count2>sum){
                sum=count1+count2;
            }
            if(nums[i]==1){
                count2++;
            }
            else if (nums[i-1]==1 && nums[i+1]==1){
                count1=count2;
                count2=0;
            }
            else {
                count1=0;
                count2=0;
            }
            
        }
        if(count1+count2>sum){
                sum=count1+count2;
            }
        return sum;
    }
};

void test1() {
    std::vector<int> nums = {1,1,0,1};
    int expected = 3;

    Solution solution;
	int output = solution.longestSubarray(nums);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums = {0,1,1,1,0,1,1,0,1};
    int expected = 5;

    Solution solution;
	int output = solution.longestSubarray(nums);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> nums = {1,1,1};
    int expected = 2;

    Solution solution;
	int output = solution.longestSubarray(nums);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}