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
    int rangeSumBST2(TreeNode* root, int low, int high,int &sum)
    {
        if(root==NULL)
            return 0;
        if(root->val>=low && root->val<=high)
            sum+=root->val;
        int lv=rangeSumBST2(root->left,low,high,sum);
        int rv=rangeSumBST2(root->right,low,high,sum);
        return lv+rv;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0;
        int sum=0;
        int res=rangeSumBST2(root,low,high,sum);
        return sum;
        
    }
};