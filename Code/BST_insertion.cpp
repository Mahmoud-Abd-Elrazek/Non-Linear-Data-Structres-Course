// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int data) : left(nullptr) , right(nullptr) , val(data) {};
};

void bfs (TreeNode* root) {
   if (root==nullptr) return;
   queue<TreeNode*>qu;
   qu.push(root);
   while(qu.empty() == false){
      int n = qu.size();
      for(int i =0;i<n;++i){
         TreeNode* f = qu.front();
         qu.pop();
         cout << f->val << " ";
         if(f->left)
            qu.push(f->left);
         if(f->right)
            qu.push(f->right);
      }
      cout << endl;
   }
}

TreeNode* insert (TreeNode* root, int value) { 

   if (root == nullptr)
   {
      return new TreeNode(value);
   }
   if (value < root->val) { // go left 
      root->left = insert(root->left, value);
   }
   else { // go right
      root->right = insert(root->right, value);
   }

   return root;
}
int main () {
   TreeNode* root = nullptr;
   root = insert(root,50);
   insert(root,60);
   insert(root,30);
   insert(root,10);

   bfs(root); // print root of bst
   return 0;
}