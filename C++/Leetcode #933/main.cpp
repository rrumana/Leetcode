#include <iostream>
#include <vector>
#include <queue>

class RecentCounter {
public:
    RecentCounter() {}
    
    int ping(int t) {

    }
};

void test1() {
    RecentCounter* obj = new RecentCounter();
    std::vector<int> pings = {1,100,3001,3002};
    std::vector<int> expected = {1,2,3,3};
    std::vector<int> output;
    for(int x : pings){
        output.push_back(obj->ping(x));
    }

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {}

void test3() {}

int main() {
    test1();
    //test2();
    //test3();
	return 0;
}
