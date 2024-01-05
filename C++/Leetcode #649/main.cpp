#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++) {
            if(senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }

        while(!q1.empty() && !q2.empty()){
            int r_turn = q1.front(), d_turn = q2.front();
            q1.pop(), q2.pop();
            if(r_turn < d_turn) q1.push(r_turn + n);
            else q2.push(d_turn + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
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
