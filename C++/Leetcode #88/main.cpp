#include <iostream>
#include <vector> 

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int x1 = 0;
        int x2 = 0;

        while(x2 < n){
            if(nums1[x1+x2] <= nums2[x2] && x1<m)
                x1++;
            else{
                nums1.insert(nums1.begin()+x1+x2, nums2[x2]);
                nums1.pop_back();
                x2++;
            }
        }
    }
};

void test1() {
    std::vector<int> nums1{1,2,3,0,0,0};
	std::vector<int> nums2{2,5,6};
    std::vector<int> expected{1,2,2,3,5,6};
	int m = 3;
	int n = 3;

	Solution solution;
	solution.merge (nums1, m, nums2, n);

	if(nums1 == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> nums1{1};
	std::vector<int> nums2{};
    std::vector<int> expected{1};
	int m = 1;
	int n = 0;

	Solution solution;
	solution.merge (nums1, m, nums2, n);

	if(nums1 == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> nums1{0};
	std::vector<int> nums2{1};
    std::vector<int> expected{1};
	int m = 0;
	int n = 1;

	Solution solution;
	solution.merge (nums1, m, nums2, n);

	if(nums1 == expected) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}