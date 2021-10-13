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
    TreeNode* build(vector<int>& preorder, int &i,int limit=INT_MAX)
    {
        if(i==preorder.size() ||preorder[i]>limit)
            return NULL;
        int val=preorder[i++];
        TreeNode* root= new TreeNode(val);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,limit);
        return root;
            
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
        
        
    }
};