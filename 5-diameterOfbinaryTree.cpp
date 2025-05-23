#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root, int& maxdia){
        if(root==NULL) return;
        int dia=levels(root->left)+levels(root->right);
        maxdia=max(maxdia,dia);
        helper(root->left,maxdia);
        helper(root->right,maxdia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        helper(root,maxdia);
        return maxdia;
    }
};