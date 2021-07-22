// Problem Link:  https://leetcode.com/problems/sum-root-to-leaf-numbers/

int ans=0;
    void solve(TreeNode* root,int curr){
        if(!root)
            return ;
        if(!root->left && !root->right){
            ans+=10*curr+root->val;
            return ;
        }
        curr=10*curr+root->val;
        solve(root->left,curr);
        solve(root->right,curr);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
