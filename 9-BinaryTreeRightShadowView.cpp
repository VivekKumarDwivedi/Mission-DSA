#include<bits/stdc++.h>
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
public:
    
   void helper(TreeNode* root,int level,vector<int>& vec){
    if(!root) return ;
    if(vec.size()<level) vec.push_back(root->val);
    helper(root->right,level+1,vec);
    helper(root->left,level+1,vec);
     return;
   
   }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        helper(root,1,vec);
        return vec;
    }
};