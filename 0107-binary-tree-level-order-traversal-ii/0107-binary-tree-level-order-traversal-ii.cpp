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
    int m=0;
    void height(TreeNode* r,int h)
    {
        if(!r)
        {
            m=max(m,h-1);
            return ;
        }
        height(r->left,h+1);
        height(r->right,h+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        height(root,0);
        vector<vector<int>>ans(m+1);
        queue<TreeNode*>q;
        if(!root)
        return {};
        q.push(root);
        while(q.size())
        {
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++)
            {
                TreeNode* r=q.front();
                q.pop();
                v.push_back(r->val);
                if(r->left)
                q.push(r->left);
                if(r->right)
                q.push(r->right);
            }
            ans[m--]=v;
        }
        return ans;
    }
};