// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int data) : left(nullptr) , right(nullptr) , val(data) {};
};

void preOrder (TreeNode* root) {
   if (root == nullptr)
      return;
   
   cout << root->val << " ";
   preOrder(root->left);
   preOrder(root->right);
}

TreeNode* clone (TreeNode* root) {

   if (root == nullptr) {
      return nullptr;
   }

   TreeNode* temp = new TreeNode(root->val);
   temp->left = clone(root->left);
   temp->right = clone(root->right);

   return temp;
}

int main () {
   TreeNode* root = new TreeNode(5);
   root->left = new TreeNode(8);
   root->right = new TreeNode(4);

   root->left->left = new TreeNode(9);
   root->left->right = new TreeNode(2);


   TreeNode* c = clone(root);

   c->val = 900;
   preOrder(c);
   cout << "\n\n";
   preOrder(root);

/*
   root  
     \ 
      5
     / \
    8   4
   / \   
  9   2 
*/
   return 0;
}