#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include <vector>       // std::vector

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int start=0,zc=0;
        int ans=0;
        for(int end=0; end<nums.size(); end++){
            if(nums[end]==0){
                zc++;
            }
            while(zc>k){
                if(nums[start]==0){
                    zc--;
                }
                start++;
            }
            ans=std::max(end-start+1,ans);
        }
        return ans;
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

void test3() {
    std::vector<int> nums = {0,0,1,1,1,0,0};
    int k = 0;
    int expected = 3;

    Solution solution;
	int output = solution.longestOnes(nums, k);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

void test4() {
    std::vector<int> nums = {0,0,0,1};
    int k = 4;
    int expected = 4;

    Solution solution;
	int output = solution.longestOnes(nums, k);

    if(output == expected) std::cout<<"Passed test 4"<<std::endl;
	else std::cout<<"Failed test 4"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
	return 0;
}