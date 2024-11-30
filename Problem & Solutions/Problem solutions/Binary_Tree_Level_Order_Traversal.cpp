// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=binary-tree

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode*> qu;
        qu.push(root);
        while (qu.empty() == false) { 
            vector<int> level;
            int number_of_nodes = qu.size();
            for (int i = 1 ; i <= number_of_nodes ; ++i) { 
                TreeNode* cur = qu.front();
                qu.pop();

                level.push_back(cur->val);
                if (cur->left != nullptr)
                    qu.push(cur->left);
                if (cur->right != nullptr)
                    qu.push(cur->right);     
            }
            ret.push_back(level);
        } // end bfs
        return ret;
    }
};
int main() {
   
   return 0;
}