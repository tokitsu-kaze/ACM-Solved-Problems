/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    void dfs(TreeNode* x,int now)
    {
        if(x==NULL) return;
        now+=x->val;
        if(x->left==NULL&&x->right==NULL)
        {
            ans+=now;
            return;
        }
        dfs(x->left,now*10);
        dfs(x->right,now*10);
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        dfs(root,0);
        return ans;
    }
};
