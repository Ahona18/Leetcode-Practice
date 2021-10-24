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
    int lefthight(TreeNode* root)
    {
        int lh=0;
        TreeNode*tmp=root;
        while(tmp!=NULL)
        {
            tmp=tmp->left;
            lh++;
        }
        return lh;
    }
     int righthight(TreeNode* root)
    {
        int rh=0;
        TreeNode*tmp=root;
        while(tmp!=NULL)
        {
            tmp=tmp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=lefthight(root);
        int rh=righthight(root);
        if(lh==rh)
            return (1<<rh)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};