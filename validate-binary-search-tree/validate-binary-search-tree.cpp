/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isValidBST(TreeNode* root,TreeNode* left=NULL, TreeNode* right=NULL) {
        if(root==NULL)
            return true;
        if((left!=NULL and root->val <= left->val)  or (right!=NULL and root->val >= right->val))
            return false;
        return isValidBST(root->left,left, root) and isValidBST(root->right, root, right);
        
    }
};