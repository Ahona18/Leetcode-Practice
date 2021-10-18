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
    queue<TreeNode*> q;
//         TreeNode* xparent=NULL,*yparent=NULL;
//         q.push(root);
//         while(!q.empty())
//         {
//             int n=q.size();
//             while(n--)
//             {
//                 TreeNode* tmp=q.front();
//                 if(tmp->left!=NULL)
//                 {
//                     q.push(tmp->left);
//                     if(tmp->left->val==x)
//                     {
//                         xparent=tmp;
//                     }
//                     if(tmp->left->val==y)
//                     {
//                         yparent=tmp;
//                     }   
//                 }
//                 if(tmp->right!=NULL)
//                 {
//                     q.push(tmp->right);
//                     if(tmp->right->val==x)
//                     {
//                         xparent=tmp;
//                     }
//                     if(tmp->right->val==y)
//                     {
//                         yparent=tmp;
//                     }   
//                 }
//                 if(xparent!=NULL && yparent!=NULL)
//                 {
//                     return xparent!=yparent;
//                 }
//                  if((xparent==NULL && yparent!=NULL) || (xparent!=NULL && yparent==NULL)){
//                      return false;
//                   }
                
//             }
//         }
//         return false;
        
   int count = 0;
    int parent = 0;
    
    void depth(TreeNode* root, int val, int cnt, TreeNode* prnt)
    {
        if(!root)
            return ;
         if(root -> val == val){
            count = cnt;
            parent = prnt -> val;
            if(count == 0)
                return;
        }
         cnt++;
        
        depth(root -> left, val, cnt, root);
        depth(root -> right, val, cnt, root);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {       
   int dx = 0, px = 0;
        int dy = 0, py = 0;
        
        depth(root, x, 0, root);
        dx = count;
        px = parent;
        
        depth(root, y, 0, root);
        dy = count;
        py = parent;
        
        if(dx == dy && px != py)
            return true;
        
        else
            return false;
    }
};