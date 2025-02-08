// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode { 
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int data) : val(data) , left(nullptr) , right(nullptr) {};
};
int main() {

   TreeNode* root = new TreeNode(5);
   root->left = new TreeNode(8);
   root->right = new TreeNode(4);

   root->left->left = new TreeNode(9);
   root->left->right = new TreeNode(2);

   root->right->right = new TreeNode(7);

/*
   root
      \
      5
     / \
    8   4
   / \   \
  9   2   7
*/

}