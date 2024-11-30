// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/balanced-binary-tree/description/?envType=problem-list-v2&envId=binary-tree
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
    int H (TreeNode* current) {
        if (current == nullptr)
            return 0;
        
        int lf = H(current->left);
        if (lf == -1) return -1;
        int ri = H(current->right);
        if (ri == -1) return -1;

        if (abs(lf - ri) > 1)
            return -1;
        
        return max(lf,ri) + 1;

    }  
public:
    bool isBalanced(TreeNode* root) {

        return H(root) != -1;

    }
};
int main () {

    return 0;
}