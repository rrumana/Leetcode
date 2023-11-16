#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int one = word1.length();
        int two = word2.length();
        std::string merged = "";

        while(one+two > 0){
            if(one > 0){
                merged += word1[word1.length()-one];
                one--;
            }
            if(two > 0){
                merged += word2[word2.length()-two];
                two--;
            }
        }

        return merged;
    }
};

void test1() {
    std::string word1 = "abc";
    std::string word2 = "pqr";
    std::string output = "";
    std::string expected = "apbqcr";

    Solution solution;
	output = solution.mergeAlternately(word1, word2);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::string word1 = "ab";
    std::string word2 = "pqrs";
    std::string output = "";
    std::string expected = "apbqrs";

    Solution solution;
	output = solution.mergeAlternately(word1, word2);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::string word1 = "abcd";
    std::string word2 = "pq";
    std::string output = "";
    std::string expected = "apbqcd";

    Solution solution;
	output = solution.mergeAlternately(word1, word2);

    if(output == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}