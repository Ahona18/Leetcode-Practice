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
    class NodeValue{
    public:
    bool isBst;
    int minnode,maxnode,sum;
     };
    NodeValue  BST(TreeNode* root)
    {
        if(!root)
        {
            NodeValue bres;
            bres.isBst=true;
            bres.minnode=INT_MAX;
            bres.maxnode=INT_MIN;
            bres.sum=0;
            return bres;
        }
        
        auto left=BST(root->left);
        auto right=BST(root->right);
        NodeValue ans;
        ans.maxnode=max(root->val,max(left.maxnode,right.maxnode));
        ans.minnode=min(root->val,min(left.minnode,right.minnode));
        ans.isBst=left.isBst && right.isBst &&(left.maxnode < root->val && right.minnode > root->val);
        if(ans.isBst)
        {
            ans.sum=left.sum+right.sum+root->val;
            ans.maxnode=max(root->val,max(left.maxnode,right.maxnode));
            ans.minnode=min(root->val,min(left.minnode,right.minnode));
        }
        else
            ans.sum=max(left.sum,right.sum);
        res=max(res,ans.sum);
        return ans;
    }
    int res=INT_MIN;
    int maxSumBST(TreeNode* root) {
        BST(root);
        return res>0?res:0;
    }
};