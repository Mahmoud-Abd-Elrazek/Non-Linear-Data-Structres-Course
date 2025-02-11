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

/*
   .1 Intialize a Queue: 
      Start by empty queue and push the root node.
   .2 Travese Level by Level:
      2.1 pop front of the queue
      2.2 process (e.g., print its value)
      2.3 if current has a left child
         2.3.1 push into queue
      2.4 if current has a right child
         2.4.1 push into queue
   .3 Repeat:
      continue until the queue is empty


   time complexity : O(N)
   space complexity : O(W)
   , W is the max number of nodes at level 'L' (maximum width of binary tree) 
*/

void BFS (TreeNode* r) { 
   if (r == nullptr)
      return;

   queue<TreeNode*> qu;
   qu.push(r);

   while (qu.empty() == false) {

      int num_of_nodes = qu.size();

      while (num_of_nodes--) { 
         TreeNode* cur = qu.front();
         qu.pop();

         cout << cur->val << " ";

         if (cur->left != nullptr) 
            qu.push(cur->left);
            
         if (cur->right != nullptr) 
            qu.push(cur->right);
      }

      cout << endl;

   } // end bfs
}

/*
   Write a function takes a root of binary tree 
   and return number of leaves 'use BFS algorithm'

   F (root) { 
      return number of leaves in BT
   }
     root
        \
         10
        / \
       8   20
      / \    \
     9   50   6
    / \
   7   5
   output: 4 leaves [7,5,50,6]
*/

int main() {

   TreeNode* root = new TreeNode(5);
   root->left = new TreeNode(8);
   root->right = new TreeNode(4);

   root->left->left = new TreeNode(9);
   root->left->right = new TreeNode(2);

   root->right->right = new TreeNode(7);

   BFS(root);

/*
   root
      \
      5
     / \
    8   4
   / \   \
  9   2   7

  5
  8 4 
  9 2 7
*/

}