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
    // void inorder(vector<int> &inord,TreeNode* root)
    // {
    //     if(!root)
    //         return ;
    //     inorder(inord,root->left);
    //     inord.push_back(root->val);
    //     inorder(inord,root->right);
    // }
    int count=0,ans=0;
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> inord;
        // inorder(inord,root);
        // for(auto i:inord)
        //     cout<<i<<" ";
        // return inord[k-1];
        if(!root)
            return ans;
        kthSmallest(root->left,k);
        count++;
        if(count==k)
            ans=root->val;
        kthSmallest(root->right,k);
        return ans;
        
        
    }
};