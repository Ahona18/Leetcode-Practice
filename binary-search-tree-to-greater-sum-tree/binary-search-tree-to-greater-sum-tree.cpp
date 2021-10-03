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
    void transform(TreeNode* root,int &rightsum)
    {
        if(!root)
            return ;
        transform(root->right,rightsum);
         root->val+=rightsum;
        rightsum=root->val;
        transform(root->left,rightsum);
    }
    TreeNode* bstToGst(TreeNode* root) {
     
        int rightsum=0;
       transform(root,rightsum);
      return root;
    }
};