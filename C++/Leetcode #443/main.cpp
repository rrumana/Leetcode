#include <iostream>     // std::cout
#include <vector>       // std::vector

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int i = 0, res = 0;

        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }

            chars[res++] = chars[i];

            if (groupLength > 1) {
                for (char c : std::to_string(groupLength)) {
                    chars[res++] = c;
                }
            }

            i += groupLength;
        }
        return res;
    }
};

void test1() {
    std::vector<char> chars = {'a','a','b','b','c','c','c'};
    std::vector<char> expected = {'a','2','b','2','c','3'};
    int length = 6;

    Solution solution;
	int output = solution.compress(chars);

    bool correct = true;
    for(int i = 0; i < length; i++){
        if(chars[i] != expected[i]);
    }
    if(correct && output == length) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<char> chars = {'a'};
    std::vector<char> expected = {'a'};
    int length = 1;

    Solution solution;
	int output = solution.compress(chars);

    bool correct = true;
    for(int i = 0; i < length; i++){
        if(chars[i] != expected[i]);
    }
    if(correct && output == length) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    std::vector<char> expected = {'a','b','1','2'};
    int length = 4;

    Solution solution;
	int output = solution.compress(chars);

    bool correct = true;
    for(int i = 0; i < length; i++){
        if(chars[i] != expected[i]);
    }
    if(correct && output == length) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}