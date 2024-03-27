#include <iostream>         // std::cout
#include <vector>           // std::vector

class Solution {
  public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
      int count = 0;
      for (int i = 0; i < flowerbed.size(); i++) {
        if(flowerbed[i] == 0) {
          int prev = i ? flowerbed[i - 1] : 0;
          int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];
          if(prev == 0 && next == 0) {
            flowerbed[i] = 1;
            count++;
          }
        }
      }
      return count >= n;
    }
};

void test1() {
  std::vector<int> flowerbed = {1,0,0,0,1};
  int n = 1;

  bool expected = true;

  Solution solution;
  bool output = solution.canPlaceFlowers(flowerbed, n);

  if(expected == output) std::cout<<"Passed test 1"<<std::endl;
  else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
 std::vector<int> flowerbed = {1,0,0,0,1};
  int n = 2;

  bool expected = false;

  Solution solution;
  bool output = solution.canPlaceFlowers(flowerbed, n);

  if(expected == output) std::cout<<"Passed test 2"<<std::endl;
  else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
}

int main() {
  test1();
  test2();
  //test3();
  return 0;
}
