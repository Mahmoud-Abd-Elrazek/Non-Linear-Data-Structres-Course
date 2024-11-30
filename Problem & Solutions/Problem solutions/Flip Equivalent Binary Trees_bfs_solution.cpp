//لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
// problem link: https://leetcode.com/problems/flip-equivalent-binary-trees/editorial/?envType=daily-question&envId=2024-10-24

#include <bits/stdc++.h>
using namespace std;

using i64 = long long ;
#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 0x3f3f3f3f , Mod = 1e9+7 ; 

static int speedUp=[](){
   std::ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif
return 0;
}();


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
   using info = pair<TreeNode*,TreeNode*>;

   bool flipEquiv(TreeNode* root1, TreeNode* root2) {

      if (root1 == root2) return true;
      if (!root1 || !root2 || root1->val != root2->val) return false;
      
      queue<info> qu;
      qu.emplace(root1,root2);

      while(qu.empty() == false) 
      {
         auto node1 = qu.front().first;
         auto node2 = qu.front().second;

         qu.pop();

         if (node1 == node2) continue;
         if (!node1 || !node2 || node1->val != node2->val) return false;

         auto L1 = node1->left , L2 = node2->left;
         auto R1 = node1->right , R2 = node2->right;

         if (((!L1 && !L2) || (L1 && L2 && L1->val == L2->val)) &&
               ((!R1 && !R2) || (R1 && R2 && R1->val == R2->val))) 
         {
               qu.emplace(L1, L2);
               qu.emplace(R1, R2);
         }

         else if (((!L1 && !R2) || (L1 && R2 && L1->val == R2->val)) &&
                  ((!R1 && !L2) || (R1 && L2 && R1->val == L2->val)))
         {
               qu.emplace(L1, R2);
               qu.emplace(R1, L2);
         } 
         else return false;

      } // end bfs

      return true;

   }
};

int main () {


}
