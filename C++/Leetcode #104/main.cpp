#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::max
#include <optional>     // std::optional
#include <cstddef>      // std::size_t

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return std::max(maxLeft, maxRight) + 1;
    }
};

TreeNode* constructTree(const std::vector<std::optional<int>>& vec, std::size_t index) {
    if (index >= vec.size() || !vec[index].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*vec[index]);
    root->left = constructTree(vec, 2 * index + 1);
    root->right = constructTree(vec, 2 * index + 2);
    return root;
}

void displayAll(TreeNode* root) {
	if(root) {
		std::cout<<root->val<<" ";
		displayAll(root->left);	
		displayAll(root->right);		
	}
}

void test1() {
    std::vector<std::optional<int>> Vec = {3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    int expected = 3;

    TreeNode* root1 = constructTree(Vec, 0);

    Solution solution;
	int output = solution.maxDepth(root1);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<std::optional<int>> Vec = {1, std::nullopt, 2};
    int expected = 2;

    TreeNode* root1 = constructTree(Vec, 0);

    Solution solution;
	int output = solution.maxDepth(root1);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {}

int main() {
    test1();
    test2();
	return 0;
}
