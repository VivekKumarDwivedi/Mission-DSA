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
 
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* r=new TreeNode(val); 
        if(root==NULL) {
           
            return r;
        }
        TreeNode* temp=root;
      while(temp){
        if(temp->val< val){
            if(temp->right==NULL) 
              {temp->right=r;
              break;}

           else  temp=temp->right;
        }
        else{
             if(temp->left==NULL) 
               {temp->left=r;
               break;}

            else  temp=temp->left;
        }
    
      }
       return root;
    }
};