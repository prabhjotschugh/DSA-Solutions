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
    bool isCompleteTree(TreeNode* root) {
      queue<TreeNode*> storeNodes;
        storeNodes.push(root);
        bool isNullInBetweenNodes = false;
        while (!storeNodes.empty()) {
            int totalNodesInLevel = storeNodes.size();
            while (totalNodesInLevel--) {
                TreeNode *currNode = storeNodes.front();
                storeNodes.pop();
                if (currNode == nullptr) {
                    isNullInBetweenNodes = true;
                }
                else {
                    if (isNullInBetweenNodes == true) {
                        return false;
                    }
                    storeNodes.push(currNode -> left);
                    storeNodes.push(currNode -> right);
                }
            }
        }
        return true;  
    }
};