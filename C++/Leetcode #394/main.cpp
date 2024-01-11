#include <iostream>         // std::cout
#include <stack>            // std::stack

class Solution {
public:
    std::string makeString(int n, std::string s) {
        std::string temp = "";
        for(int i = 0; i < n; i++) temp += s;
        return temp;
    }

   std::string decodeString(std::string s) {
      int i=0;
      while (i < s.size()) {
         if (s[i] != ']') {
            i++;
            continue;
         }

         int j = i;
         while (s[j] != '[') j--;
         std::string repeatLetters{ s.substr(j + 1, i - j - 1) };
         auto k{ j };
         j--;
         while (j > 0 && isdigit(s[j]))
            j--;
         if (j != 0) j++;
         int n = stoi(s.substr(j, k - j));
         s.replace(j, i - j + 1, makeString(n, repeatLetters));
         i = j + repeatLetters.size() * n;
      }
      return s;
   }
};

void test1() {
    std::string input = "3[a]2[bc]";
    std::string expected = "aaabcbc";

    Solution solution;
	std::string output = solution.decodeString(input);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::string input = "3[a2[c]]";
    std::string expected = "accaccacc";

    Solution solution;
	std::string output = solution.decodeString(input);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::string input = "2[abc]3[cd]ef";
    std::string expected = "abcabccdcdcdef";

    Solution solution;
	std::string output = solution.decodeString(input);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}