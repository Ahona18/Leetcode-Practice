/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>>res;
        if(!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v1;
            while(n--)
            {
                Node* tmp=q.front();
                v1.push_back(tmp->val);
                for(auto i:tmp->children)
                {
                    q.push(i);
                }
                q.pop();
            }
            res.push_back(v1);
        }
        return res;
    }
};