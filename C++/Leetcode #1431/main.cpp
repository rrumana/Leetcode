#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
    std::vector<bool> result;

    int max = 0;
    for(auto x : candies) {
      if(x > max) max = x;
    }

    int min = max - extraCandies;

    for(auto x : candies) {
      if(x >= min) result.push_back(true);
      else result.push_back(false);
    }

    return result;
  }
};

void test1() {
  std::vector<int> input = {2,3,5,1,3};
  int candies = 3;
  std::vector<bool> output;
  std::vector<bool> expected = {true, true, true, false, true};

  Solution solution;
	output = solution.kidsWithCandies(input, candies);

  if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::vector<int> input = {4,2,1,1,2};
  int candies = 1;
  std::vector<bool> output;
  std::vector<bool> expected = {true, false, false, false, false};

  Solution solution;
	output = solution.kidsWithCandies(input, candies);

  if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
}

int main() {
  test1();
  test2();
  test3();
}
