// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        stack<vector<int>> bottomUp;
        queue<TreeNode*> qu;
        qu.push(root);
        while (qu.empty() == false) {
            vector<int> level;
            int N = qu.size();
            while (N--) {
                TreeNode*cur = qu.front();
                qu.pop();
                level.push_back(cur->val);
                if (cur->left != nullptr)
                    qu.push(cur->left);
                if (cur->right != nullptr)
                    qu.push(cur->right);
            } // end level
            ret.push_back(level);
        }// end bfs

        reverse(ret.begin() , ret.end());
        return ret;
    }
};

int main() {
   
   return 0;
}