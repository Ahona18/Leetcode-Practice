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
    int res=0;
    void patsum2(TreeNode* root, int targetSum)
    {
        if(!root)
            return;
        if(targetSum==root->val)
            res++;
        targetSum=targetSum-root->val;
        patsum2(root->left,targetSum);
        patsum2(root->right,targetSum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        patsum2(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return res;
        
    }
};