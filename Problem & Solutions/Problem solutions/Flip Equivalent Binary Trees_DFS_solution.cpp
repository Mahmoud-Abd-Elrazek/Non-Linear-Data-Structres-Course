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

   bool flipEquiv(TreeNode* root1, TreeNode* root2) {


      if (root1 == nullptr && root2 == nullptr) return true;

      if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
         return false;
      
      auto L1 = root1->left , L2 = root2->left;
      auto R1 = root1->right , R2 = root2->right;

      return (flipEquiv(L1,L2) && flipEquiv(R1,R2)) || (flipEquiv(L1,R2) && flipEquiv(L2,R1));
      
   }
};

int main () {


}
