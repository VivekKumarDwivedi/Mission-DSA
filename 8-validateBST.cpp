
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
     TreeNode* prev=NULL;
     bool flag=true;

    void Inorder(TreeNode* root){
        if(root==NULL) return;
        Inorder(root->left);
        if(prev!=NULL){
            if(root->val<=prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        Inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        Inorder(root);
        return flag;
    }
};