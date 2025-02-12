#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) : left(nullptr), right(nullptr), val(data) {};
};

void dfs (TreeNode* root) {
	if (root == nullptr)
		return;
	cout << root->val << " ";
	dfs(root->left);
	dfs(root->right);
}

void deleteBT (TreeNode*& current) { 

    if (current == nullptr) {
        return;
    }
    deleteBT(current->left);
    deleteBT(current->right);
    delete current;
    current = nullptr;
}

int main() {

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(8);
	root->right = new TreeNode(4);

	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(2);

	root->right->right = new TreeNode(7);
	
	dfs(root);
	cout << "\n";
	deleteBT(root);

	cout << "Hello World\n";
	dfs(root);
	
	/*
	   root
	     \
	      5
	     / \
	    8   4
	   / \   \
	  9   2   7
	*/


	return 0;
}