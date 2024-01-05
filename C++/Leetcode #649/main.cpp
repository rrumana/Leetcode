#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {

    }
};

void test1() {
    std::string senate = "RD";
    std::string expected = "Radiant";

    Solution solution;
	std::string output = solution.predictPartyVictory (senate);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::string senate = "RDD";
    std::string expected = "Dire";

    Solution solution;
	std::string output = solution.predictPartyVictory (senate);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {}

int main() {
    test1();
    test2();
    //test3();
	return 0;
}
