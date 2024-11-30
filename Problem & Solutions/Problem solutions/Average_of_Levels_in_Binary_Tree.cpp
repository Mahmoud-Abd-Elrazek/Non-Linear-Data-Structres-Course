// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

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
   vector<double> averageOfLevels(TreeNode* root) {
      using i64 = long long ;
      vector<double> ans;
      if(root == nullptr)
        return ans;
      queue<TreeNode*> qu;
      qu.push(root);

      int N = 0;
      while (qu.empty() == false) 
      {
         N = qu.size(); // number of node at level L
         i64 levelSum = 0;
         for (int i = 1 ; i <= N ; ++i)
         {
            TreeNode* cur = qu.front();
            qu.pop();
            levelSum += cur->val;
            if (cur->left != nullptr)
               qu.push(cur->left);
            if (cur->right != nullptr)
               qu.push(cur->right);
         }

         double avg_ = levelSum / double(N); 

         ans.push_back(avg_);
      } // end bfs
      return ans;
   }

};

int main() {
   
   return 0;
}