#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
  std::string reverseWords(std::string s) {
    std::stringstream ss(s);
    std::string word, output;
    while(ss >> word)  {
      output = word + " " + output;
    }
    return output.substr(0, output.size()-1);
  }
};

void test1() {
  std::string input = "The sky is blue";
  std::string expected = "blue is sky The";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::string input = "  hello world ";
  std::string expected = "world hello";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
  std::string input = "a good   example";
  std::string expected = "example good a";

  Solution solution;
  std::string output = solution.reverseWords(input);

  if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
  test1();
  test2();
  test3();
}
