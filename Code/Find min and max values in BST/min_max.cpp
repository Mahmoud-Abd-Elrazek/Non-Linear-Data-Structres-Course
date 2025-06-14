// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int data) : left(NULL) , right(NULL) , val(data) {};
};

void BFS (TreeNode* r) { 
   if (r == NULL)
      return;

   queue<TreeNode*> qu;
   qu.push(r);
   while (qu.empty() == false) {

      int num_of_nodes = qu.size();
      while (num_of_nodes--) { 
         TreeNode* cur = qu.front();
         qu.pop();

         cout << cur->val << " ";

         if (cur->left != NULL) 
            qu.push(cur->left);
            
         if (cur->right != NULL) 
            qu.push(cur->right);
      }

      cout << endl;

   } // end bfs
}

TreeNode* insert (TreeNode* root, int value) {
   if (root == NULL){
      TreeNode* newNode = new TreeNode(value);
      return newNode;
   }

   if (root->val > value)
      root->left = insert(root->left,value);
   else 
      root->right = insert(root->right,value);
   return root;
}

TreeNode* findMin (TreeNode* root) {
   if (root == NULL) return NULL;
   while ( root ->left != NULL) {
      root = root->left;
   }

   return root;
}
TreeNode* findMax (TreeNode* root) {
   if (root == NULL) return NULL;
   while ( root ->right != NULL) {
      root = root->right;
   }

   return root;
}

int main () {
   TreeNode* root = NULL;
   root = insert(root,30);
   root = insert(root,20);
   root = insert(root,80);
   // root = insert(root,10);
   root = insert(root,70);
   root = insert(root,50);
   root = insert(root,90);
   
   cout << "Min Value: " << findMin(root)->val << endl;
   cout << "Max Value: " << findMax(root)->val << endl;
   if (root != NULL) BFS(root);
   else cout << "The tree is empty." << endl;
   
   return 0;
}