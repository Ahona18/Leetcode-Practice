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
    void dfs(TreeNode* root,string path ,vector<string> &res)
    {
        if(root==NULL)return;
        path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)// termination at leaf node
        {
            res.push_back(path);
            return ;   
        }
            dfs(root->left,path+"->",res);
            dfs(root->right,path+"->",res);
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string> res;
        if(root==NULL)
            return res;
        dfs(root,"",res);
        return res;
        
    }
};