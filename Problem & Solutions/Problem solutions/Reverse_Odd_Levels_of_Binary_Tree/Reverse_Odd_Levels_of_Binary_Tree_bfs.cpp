// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000000;

static int speedUp = []()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
   return 0;
}();
struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
   TreeNode *bfs(TreeNode *root)
   {
      if (root == nullptr)
         return root;

      queue<TreeNode *> qu;
      qu.push(root);

      int level = 0, N = 1;

      while (qu.empty() == false)
      {
         N = qu.size();
         stack<TreeNode *> temp;
         bool reach_half = false;
         while (N--)
         {
            TreeNode *front = qu.front();
            qu.pop();

            if (front->left != nullptr)
               qu.push(front->left);

            if (front->right != nullptr)
               qu.push(front->right);

            if (level & 1)
            {
               if (temp.size() == ((int)pow(2, level) >> 1))
                  reach_half = true;
               else if (reach_half != true)
                  temp.push(front);
               
               if (reach_half) {
                  swap(temp.top()->val, front->val);
                  temp.pop();
               }
            }
         }
         level++;
      }
      return root;
   }

public:
   TreeNode *reverseOddLevels(TreeNode *root)
   {
      return bfs(root);
   }
};

int main()
{

   return 0;
}