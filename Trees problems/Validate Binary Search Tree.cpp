// Problem Link:  https://leetcode.com/problems/validate-binary-search-tree/

bool solve(TreeNode* root,long long int minn,long long int maxx){
        if(!root)
            return true;
        if(root->val>minn && root->val<maxx && solve(root->left,minn,root->val) && solve(root->right,root->val,maxx))
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long minn=INT_MIN,maxx=INT_MAX;
        return solve(root,minn-1,maxx+1);
    }
