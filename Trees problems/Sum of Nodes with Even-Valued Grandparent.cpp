// Problem Link:  https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

int solve(TreeNode* root,int par,int parr){
        if(!root)
            return 0;
        int l=solve(root->left,root->val,par);
        int r=solve(root->right,root->val,par);
        if(parr%2==0){
            return l+r+root->val;
        }
        return l+r;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root,-1,-1);
    }
