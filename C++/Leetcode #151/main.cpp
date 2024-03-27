#include <iostream>         // std::cout
#include <vector>           // std::vector
#include <algorithm>        // std::reverse
#include <string>           // std::string
                            
class Solution {
  public:
    std::string reverseWords(std::string s) {
      reverse(s.begin(),s.end());
      int n=s.size();
      int left=0;
      int right=0;
      int i=0;
      while(i<n){
        while(i<n && s[i]==' ')i++;
        if(i==n)break; // to stop index going out of bounds
        while(i<n && s[i]!=' '){
          s[right++]=s[i++];
        }
        reverse(s.begin()+left,s.begin()+right);
        s[right++]=' ';
        left=right;
        i++;
      }
      s.resize(right-1);
      return s;
    }
};

void test1() {
  std::string input = "the sky is blue";
  std::string expected = "blue is sky the";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(expected == output) std::cout<<"Passed test 1"<<std::endl;
  else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::string input = "  hello world  ";
  std::string expected = "world hello";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(expected == output) std::cout<<"Passed test 2"<<std::endl;
  else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
  std::string input = "a good   example";
  std::string expected = "example good a";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(expected == output) std::cout<<"Passed test 3"<<std::endl;
  else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
