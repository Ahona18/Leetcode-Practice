/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        queue<Node*>Q;
        Q.push(node);
        unordered_map<Node*,Node*> vis;
        vis[node]=new Node(node->val);
        while(!Q.empty())
        {
            int n=Q.size();
            Node *curr=Q.front();
            Q.pop();
            for(auto i:curr->neighbors)
            {
                if(!vis[i])
                {
                    vis[i]=new Node(i->val);
                    Q.push(i);
                }
                vis[curr]->neighbors.push_back(vis[i]);
            }
            
        }
        
        return vis[node];
    }
};