// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/?envType=problem-list-v2&envId=binary-search-tree

#include <iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   ListNode* getMidList (ListNode*head , ListNode*end = nullptr) { 

      ListNode* slow = head, *fast = head;

      while (fast != end && fast->next != end) {
         slow = slow->next;
         fast = fast->next->next;
      }

      cout << (fast == nullptr ? "Even" : "Odd") << endl;
      return slow;

   }

   TreeNode* bulidBST (ListNode*start,ListNode*end) { 
      if (start == end) 
         return nullptr;
      
      ListNode* mid = getMidList(start,end);
      TreeNode* root = new TreeNode(mid->val);

      root->left = bulidBST(start , mid);   
      root->right = bulidBST(mid->next , end);   

      return root;
   }
public:

   TreeNode* sortedListToBST(ListNode* head) {
      return bulidBST(head,nullptr);
   }

};
int main() {
   
   return 0;
}