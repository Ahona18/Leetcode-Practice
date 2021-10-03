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
    vector<int> postorder(Node* root) {
       vector<int>res;
        if(!root)
            return res;
        stack<Node*>s;
        s.push(root);
        while(!s.empty())
        {
            Node* tmp=s.top();
            s.pop();
            for(int i=0;i<tmp->children.size();i++)
                s.push(tmp->children[i]);
            res.push_back(tmp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};