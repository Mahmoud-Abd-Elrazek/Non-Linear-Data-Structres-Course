// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;

struct TreeNode { 
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode (const int& val) : left(nullptr) , right(nullptr) , val(val) {}
};

void preorder (TreeNode* root) { 
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder (TreeNode* root) { 
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


void postorder (TreeNode* root) { 
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main () {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(7);

    preorder(root);
    cout << "\n"; // 5 8 9 2 4 7
    
    inorder(root);
    cout << "\n"; // 9 8 2 5 4 7

    postorder(root);
    cout << "\n"; // 2 9 8 7 4 5
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