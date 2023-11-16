#include <iostream>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++){
        nums[i] = std::max(nums[i] + i, nums[i-1]);
      }

      int index = 0;
      int answer = 0;

      while(index < nums.size() - 1){
        answer++;
        index = nums[index];
      }

      return answer;
    }
};

void test1() {
    std::vector<int> input = {2,3,1,1,4};
    int output;
    int expected = 2;

    Solution solution;
	output = solution.jump(input);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> input = {2,3,0,1,4};
    int output = 0;
    int expected = 2;

    Solution solution;
	output = solution.jump(input);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

int main() {
    test1();
    test2();
	return 0;
}