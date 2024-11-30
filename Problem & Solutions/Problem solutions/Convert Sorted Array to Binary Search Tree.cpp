// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// prooblem link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=problem-list-v2&envId=binary-search-tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    TreeNode* convertBST(int left, int right, vector<int>& arr) {
        if(left > right)
            return nullptr;

        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = convertBST(left, mid - 1, arr);
        root -> right = convertBST(mid + 1, right, arr);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size() - 1;
        return convertBST(0, size, nums);
    }
};

int main() {
   

}