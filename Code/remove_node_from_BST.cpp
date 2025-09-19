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

TreeNode* removeNode (TreeNode* root, int key) {

   if (root == NULL)
      return NULL;

   // search 
   if (root->val > key) // go left
      root->left = removeNode(root->left,key);

   else if (root->val < key)
      root->right = removeNode(root->right,key);
   else {

      if (root->left == NULL) { 
         TreeNode* temp = root->right;
         delete root;
         return temp;
      }
      else if (root->right == NULL) { 
         TreeNode* temp = root->left;
         delete root;
         return temp;
      }

      // case 3

      TreeNode* mn = findMin(root->right);
      root->val = mn->val;
      
      root->right = removeNode(root->right,mn->val);
   }

   return root;

}

int main () {
   TreeNode* root = NULL;
   root = insert(root,50);
   root = insert(root,20);
   root = insert(root,70);
   root = insert(root,10);
   root = insert(root,30);
   root = insert(root,25);
   root = insert(root,40);
   root = insert(root,60);
   root = insert(root,80);

   root = removeNode(root,10);
   root = removeNode(root,20);
   root = removeNode(root,50);
   root = removeNode(root,30);
   root = removeNode(root,60);
   root = removeNode(root,40);
   root = removeNode(root,70);
   root = removeNode(root,25);
   root = removeNode(root,80);


   if (root == NULL) 
      cout << "Tree is empty!" << endl;
   else 
      BFS(root);

   return 0;
}