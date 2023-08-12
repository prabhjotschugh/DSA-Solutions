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
    static bool comp(pair<int,int> a, pair<int,int> b){ 
        if(a.first==b.first)
            return a.second<=b.second;
        else
            return a.first<b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        map<int,vector<pair<int,int>>>  mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int height = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int hDist = q.front().second;
                q.pop();

                mp[hDist].push_back({height, node->val});
                if (node->left)  q.push({node->left, hDist - 1});
                if (node->right) q.push({node->right, hDist + 1});
            }
            height++;
        }
        for(auto pairs:mp){
            sort(pairs.second.begin(),pairs.second.end(),comp);
            vector<int> temp;
            for(auto ele:pairs.second){
                temp.push_back(ele.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};