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
    vector<string> ans;
    void helper(string s, TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            if(!s.empty()){
                s+="->";
            }
           s+=to_string(root->val);
           ans.push_back(s);
           return;
        }
    if(root->left==NULL && root->right!=NULL) {
               if(!s.empty()){
                s+="->";
            }
             s+=to_string(root->val);
             helper(s,root->right);
             s.pop_back();
      }
    else if(root->left!=NULL && root->right==NULL){
         if(!s.empty()){
                s+="->";
            }
        s+=to_string(root->val);
        helper(s,root->left);
        s.pop_back();
    }
    else{
         if(!s.empty()){
                s+="->";
            }
        s+=to_string(root->val);
        helper(s,root->left);
        helper(s,root->right);

    }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        helper(s,root);
        return ans;
    }
};