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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *now, *pre, *tmp, *pretmp;
        int dir,tmpdir;
        pre=NULL;
        now=root;
        while(now)
        {
            if(key>now->val)
            {
                dir=1;
                pre=now;
                now=now->right;
            }
            else if(key<now->val)
            {
                dir=0;
                pre=now;
                now=now->left;
            }
            else
            {
                if(!now->left)
                {
                    if(pre==NULL) root=now->right;
                    else
                    {
                        if(dir==0) pre->left=now->right;
                        else pre->right=now->right;
                    }
                }
                else if(!now->right)
                {
                    if(pre==NULL) root=now->left;
                    else
                    {
                        if(dir==0) pre->left=now->left;
                        else pre->right=now->left;
                    }
                }
                else
                {
                    pretmp=now;
                    tmp=now->left;
                    tmpdir=0;
                    while(tmp->right)
                    {
                        tmpdir=1;
                        pretmp=tmp;
                        tmp=tmp->right;
                    }
                    if(tmpdir==0) pretmp->left=NULL;
                    else if(tmpdir==1) pretmp->right=tmp->left;
                    if(pre==NULL)
                    {
                        if(pretmp==now) tmp->right=now->right;
                        else
                        {
                            tmp->left=now->left;
                            tmp->right=now->right;
                        }
                        root=tmp;
                    }
                    else
                    {
                        if(dir==0) pre->left=tmp;
                        else pre->right=tmp;
                        if(pretmp==now) tmp->right=now->right;
                        else
                        {
                            tmp->left=now->left;
                            tmp->right=now->right;
                        }
                    }
                }
                break;
            }
        }
        return root;
    }
};
