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
        if (!root) return {};
        vector<int> res;
        function<void(Node*)> dfs = [&](Node* node) {
            for (Node* child : node->children) {
                dfs(child);
            }
            res.push_back(node->val);
        };
        dfs(root);
        return res;
    }
};