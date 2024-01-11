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
    map<int, vector<int>> mp;
    int ans=0;
    map<int, bool>vis;
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
            vis[root->val]=false;
        if (root->left) {
            mp[root->left->val].push_back(root->val);
            mp[root->val].push_back(root->left->val);
            dfs(root->left);
        }
        if (root->right) {
            mp[root->right->val].push_back(root->val);
            mp[root->val].push_back(root->right->val);
            dfs(root->right);
        }
        return;
    }

    int amountOfTime(TreeNode* root, int start) { 
        dfs(root); 
        
        queue<pair<int, int>>Q;
        Q.push({start, 0});
        vis[start]=true;
        while(!Q.empty()){
            pair<int, int>pr=Q.front();

            Q.pop();
            int currNode=pr.first, time=pr.second;
            vis[currNode]=true;
            ans=max(ans, time);
            for(auto n:mp[currNode]){
                if(vis[n]==false) Q.push({n, time+1});
            }

        }
        return ans;
    }
};