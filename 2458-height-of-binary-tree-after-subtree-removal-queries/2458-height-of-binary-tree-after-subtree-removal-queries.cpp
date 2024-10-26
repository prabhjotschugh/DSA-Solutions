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
map<int, int> nodeToLevel;
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> levelToHeight;

    int fillMap(TreeNode* root, int level = 0) {
        if (!root) return 0;

        nodeToLevel[root->val] = level;

        int lh = fillMap(root->left, level + 1);
        int rh = fillMap(root->right, level + 1);
        
        int height = max(lh, rh);

        levelToHeight[level].push({height, root->val});
        if (levelToHeight[level].size() > 2) {
            levelToHeight[level].pop();
        }

        return 1+height;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        nodeToLevel.clear();
        levelToHeight.clear();
        int h = fillMap(root)-1;

        vector<int> ans;
        for (auto q : queries) {
            int level = nodeToLevel[q];

            auto pq = levelToHeight[level];
            auto top2 = pq.top(); pq.pop();
            auto top1 = pq.empty() ? make_pair(0, -1) :pq.top(); pq.push(top2);

            if (q == top1.second) {
                ans.push_back(h - top1.first + top2.first);
            }
            else if(pq.size()==1 && q == top2.second){
                ans.push_back(h - top2.first - 1);
            }
            else {
                ans.push_back(h);
            }
        }

        return ans;
    }
};