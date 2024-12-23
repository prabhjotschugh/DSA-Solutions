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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> bfs;
        int ans=0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp(sz,0);
            for(int i=0;i<sz;i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                temp[i] = q.front()->val;
                q.pop();
            }
            bfs.push_back(temp);
        }
        for(int i=1;i<bfs.size();i++){
            map<int,int> mp;
            vector<int> temp = bfs[i];
            for(int j=0;j<temp.size();j++){
                mp[temp[j]]=j;
            }
            sort(temp.begin(),temp.end());
            vector<bool> vis(temp.size(),false);
            int ans1=0;
            for(int j=0;j<temp.size();j++){
                if(vis[j] || mp[temp[j]] == j) continue;
                int x=j,cz=0;
                while(!vis[x]){
                    vis[x] = true;
                    x = mp[temp[x]];
                    cz++;
                }
                if(cz > 0){
                    ans1 += (cz-1);
                }
            }
            ans += ans1;
        }
        return ans;
    }
};