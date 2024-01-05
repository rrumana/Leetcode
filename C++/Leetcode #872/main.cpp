#include <iostream>     // std::cout
#include <vector>       // std::vector

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
    void getSeq(std::vector<int>& seq,TreeNode* root){
        if(!root) return;
        if(root->left == NULL && root->right == NULL) seq.push_back(root->val);
        else {
            getSeq(seq, root->left);
            getSeq(seq, root->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> seq1,seq2;
        getSeq(seq1,root1);
        getSeq(seq2,root2);
        return seq1==seq2;
    }
};

TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

TreeNode* constructTree(std::vector<int> vec, int index, int size) {
    TreeNode *root = nullptr;

    if (index < size && vec[index] != 0) {
        root = newNode(vec[index]);
         
        root->left = constructTree(vec, 2 * index + 1, size);
        root->right = constructTree(vec, 2 * index + 2, size);
    }
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
    std::vector<int> Vec1 = {3,5,1,6,2,9,8,NULL,NULL,7,4};
    std::vector<int> Vec2 = {3,5,1,6,7,4,2,NULL,NULL,NULL,NULL,NULL,NULL,9,8};
    bool expected = true;

    TreeNode* root1 = constructTree(Vec1, 0, Vec1.size());
    TreeNode* root2 = constructTree(Vec2, 0, Vec2.size());

    Solution solution;
	bool output = solution.leafSimilar(root1, root2);

    if(output == expected) std::cout<<"Passed test 1"<<std::endl;
	else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
    std::vector<int> Vec1 = {1,2,3};
    std::vector<int> Vec2 = {1,3,2};
    bool expected = false;

    TreeNode* root1 = constructTree(Vec1, 0, Vec1.size());
    TreeNode* root2 = constructTree(Vec2, 0, Vec2.size());

    Solution solution;
	bool output = solution.leafSimilar(root1, root2);

    if(output == expected) std::cout<<"Passed test 2"<<std::endl;
	else std::cout<<"Failed test 2"<<std::endl;
}

void test3() {}

int main() {
    test1();
    test2();
	return 0;
}