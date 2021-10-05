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
    TreeNode* rebuild(vector<TreeNode*>&res,int low,int high)
    {
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        res[mid]->left=rebuild(res,low,mid-1);
        res[mid]->right=rebuild(res,mid+1,high);
        return res[mid];
    }
    void inorder(TreeNode* root,vector<TreeNode*>&res)
    {
        if(!root)
            return;
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>res;
        inorder(root,res);
        return rebuild(res,0,res.size()-1);
        
    }
};