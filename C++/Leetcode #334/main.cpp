#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
  bool increasingTriplet(std::vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] < first) first = nums[i];
      else if(nums[i] < second) second = nums[i];
      else return true;
    }

    return false;
  }
};

void test1() {
  std::vector<int> input = {1,2,3,4,5};
  bool output;
  bool expected = true;

  Solution solution;
	output = solution.increasingTriplet(input);

  if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::vector<int> input = {5,4,3,2,1};
  bool output;
  bool expected = false;

  Solution solution;
	output = solution.increasingTriplet(input);

  if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
  std::vector<int> input = {2,1,5,0,4,6};
  bool output;
  bool expected = true;

  Solution solution;
	output = solution.increasingTriplet(input);

  if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
  test1();
  test2();
  test3();
}
