#include <iostream>         // std::cout
#include <vector>           // std::vector

/**
 * Definition for singly-linked list.
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
    TreeNode* searchBST(TreeNode* root, int val) {
      if(root == NULL || root->val == val) return root;
      else if(root->val > val) return searchBST(root->left, val);
      else return searchBST(root->right, val);
    }
};

TreeNode* newNode(int value) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->val = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeNode* newNode(int value, TreeNode* left, TreeNode* right) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->val = value;
  node->left = left;
  node->right = right;
  return node;
}


TreeNode* constructTree(std::vector<int> vec, int index, int size) {
  TreeNode *root = nullptr;

  if (index < size) {
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

bool areIdentical(struct TreeNode *a, struct TreeNode *b) {
  if (a == NULL && b == NULL) return true;
  if (a == NULL || b == NULL) return false;

  return (a->val == b->val && areIdentical(a->left, b->left) && areIdentical(a->right, b->right));
}

void test1() {
  std::vector<int> InputTree = {4,2,7,1,3};
  std::vector<int> OutputTree = {2,1,3};

  int root = 2;

  TreeNode *input = constructTree(InputTree, 0, InputTree.size());
  TreeNode *expected = constructTree(OutputTree, 0, OutputTree.size());

  Solution solution;
  TreeNode *output = solution.searchBST(input, root);

  //displayAll(input);
  //displayAll(expected);
  //displayAll(output);

  if(areIdentical(output, expected)) std::cout<<"Passed test 1"<<std::endl;
  else std::cout<<"Failed test 1"<<std::endl;
}

void test2() {
  std::vector<int> InputTree = {4,2,7,1,3};
  std::vector<int> OutputTree = {};

  int root = 5;

  TreeNode *input = constructTree(InputTree, 0, InputTree.size());
  TreeNode *expected = constructTree(OutputTree, 0, OutputTree.size());

  Solution solution;
  TreeNode *output = solution.searchBST(input, root);

  //displayAll(input);
  //displayAll(expected);
  //displayAll(output);

  if(areIdentical(output, expected)) std::cout<<"Passed test 2"<<std::endl;
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
