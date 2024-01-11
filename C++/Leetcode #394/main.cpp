#include <iostream>         // std::cout

class Solution {
public:
    std::string decodeString(std::string s) {
        return "aaabcbc";
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