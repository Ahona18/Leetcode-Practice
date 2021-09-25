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
    // inorder traversal of BST prints the key values in sorted order 
    // we can perform the traversal in reverseinorder and updating the key values during that 
    
    
    void reverseinorder(TreeNode* root,int &currsum)
    {
        if(!root)
            return;
        reverseinorder(root->right,currsum);
        root->val=(currsum+=root->val);
        reverseinorder(root->left,currsum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int currsum=0;
        reverseinorder(root,currsum);
        return root;
    }
};