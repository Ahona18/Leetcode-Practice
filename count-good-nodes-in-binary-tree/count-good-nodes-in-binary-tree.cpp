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
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
         cout<<root->val<<" ";
        inorder(root->right);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        // if(root->left==NULL && root->right==NULL)
        //     return 1;
        int count=0;
        stack<pair<TreeNode*, int>> s;
        s.push({root,root->val});
        while(!s.empty())
        {
           TreeNode* tmp=s.top().first;
            int maxval=s.top().second;
             s.pop();
            if(tmp->val>=maxval) {   
                count+=1;
                maxval=tmp->val;   
            }
            if(tmp->right)
                s.push({tmp->right,maxval});
            if(tmp->left)
                s.push({tmp->left,maxval});
                   
        } 
      return count;  
        
    }
};