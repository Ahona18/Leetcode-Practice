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
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh==-1 )
            return -1;
        if(rh==-1)
            return -1;
        if(abs(rh-lh)>1)
            return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int h=height(root);
        if(h==-1)
            return false;
        else
            return true;
    }
};