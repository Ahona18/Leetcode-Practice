/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root)
    {
        if(!root)
            return;
        if(root->left!=NULL)
        {
            parent[root->left]=root;
            findparent(parent,root->left);
        }
        if(root->right!=NULL)
        {
           parent[root->right]=root;
            findparent(parent,root->right) ;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     vector<int>result;
        if(!root)
            return result;
        unordered_map<TreeNode*,TreeNode*>parent;
        findparent(parent,root);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
         int currentLevel = 0;
        while(!q.empty())
        {
            if(currentLevel==k)
                break;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
               TreeNode* curr=q.front();
                vis[curr]=true;
                q.pop();
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left];
                }
                 if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right];
                }
               if(parent[curr] && !vis[parent[curr]]) 
               {
                   q.push(parent[curr]);
                   vis[parent[curr]]=true;
               }
                
            }
            currentLevel++;
        }
        while(!q.empty())
        {
          TreeNode* curr=q.front();
                q.pop();
            result.push_back(curr->val);
        }
        return result;
        
    }
};