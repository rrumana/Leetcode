#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <stack>        // std::stack
#include <string>       // std::string

class Solution {
public:
    std::string removeStars(std::string s) {
        std::stack<char> stack;
        for(char x : s){
            if(x != '*'){
                stack.push(x);
            } else {
                stack.pop();
            }
        }
        std::string output(stack.size(), ' ');
        for(int i = stack.size()-1; i >= 0; i--){
            output[i] = stack.top();
            stack.pop();
        }
        return output;
    }
};

void test1() {
    std::string s = "leet**cod*e";
    std::string expected = "lecoe";

    Solution solution;
	std::string output = solution.removeStars(s);

    //std::cout<<"Test one output: "<<output<<std::endl;

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::string s = "erase*****";
    std::string expected = "";

    Solution solution;
	std::string output = solution.removeStars(s);

    //std::cout<<"Test two output: "<<output<<std::endl;

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
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