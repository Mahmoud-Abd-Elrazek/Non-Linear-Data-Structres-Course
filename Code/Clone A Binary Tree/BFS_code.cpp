// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode( int data ) : left(nullptr) , right(nullptr) , val(data) {};
};

TreeNode* CopyBinaryTree (TreeNode* current) { 

   if (current == nullptr)
      return nullptr;

   TreeNode* copiedTreeRoot = new TreeNode(current->val); 
   
   queue<TreeNode*> currentQueue , copiedQueue;
   currentQueue.push(current);
   copiedQueue.push(copiedTreeRoot);

   while (currentQueue.empty() == false) { 
      TreeNode* front = currentQueue.front();
      TreeNode* copiedNode = copiedQueue.front();
      currentQueue.pop();
      copiedQueue.pop();
      
      if (front->left != nullptr) { 
         copiedNode->left = new TreeNode(front->left->val);

         copiedQueue.push(copiedNode->left);
         currentQueue.push(front->left);
      }

      if (front->right != nullptr) {
         copiedNode->right = new TreeNode(front->right->val);

         copiedQueue.push(copiedNode->right);
         currentQueue.push(front->right);
      }
   }

   return copiedTreeRoot;
}

int main () { 
   TreeNode* root = new TreeNode(5);
   root->left = new TreeNode(8);
   root->right = new TreeNode(4);

   root->left->left = new TreeNode(9);
   root->left->right = new TreeNode(2);
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