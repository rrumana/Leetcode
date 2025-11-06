#include <iostream>     // std::cout
#include <vector>       // std::vector

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};

ListNode* constructList(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy.next;
}

void displayAll(ListNode* root) {
	if(root) {
		std::cout<<root->val<<" ";
		displayAll(root->next);		
	}
}

bool listsEqual(ListNode* lhs, ListNode* rhs) {
    while (lhs && rhs) {
        if (lhs->val != rhs->val) return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return lhs == nullptr && rhs == nullptr;
}

void test1() {
    std::vector<int> Vec1 = {2, 4, 3};
    std::vector<int> Vec2 = {5, 6, 4};
    std::vector<int> Vec3 = {7, 0, 8};

    ListNode* List1 = constructList(Vec1);
    ListNode* List2 = constructList(Vec2);
    ListNode* expected = constructList(Vec3);

    Solution solution;
	ListNode* output = solution.addTwoNumbers(List1, List2);

    if(listsEqual(output, expected)) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> Vec1 = {0};
    std::vector<int> Vec2 = {0};
    std::vector<int> Vec3 = {0};

    ListNode* List1 = constructList(Vec1);
    ListNode* List2 = constructList(Vec2);
    ListNode* expected = constructList(Vec3);

    Solution solution;
	ListNode* output = solution.addTwoNumbers(List1, List2);

    if(listsEqual(output, expected)) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {
    std::vector<int> Vec1 = {9, 9, 9, 9, 9, 9, 9};
    std::vector<int> Vec2 = {9, 9, 9, 9};
    std::vector<int> Vec3 = {8, 9, 9, 9, 0, 0, 0, 1};

    ListNode* List1 = constructList(Vec1);
    ListNode* List2 = constructList(Vec2);
    ListNode* expected = constructList(Vec3);

    Solution solution;
	ListNode* output = solution.addTwoNumbers(List1, List2);

    if(listsEqual(output, expected)) std::cout<<"Passed test 3"<<std::endl;
	else std::cout<<"Failed test 3"<<std::endl;
}

int main() {
    test1();
    test2();
    test3();
	return 0;
}
