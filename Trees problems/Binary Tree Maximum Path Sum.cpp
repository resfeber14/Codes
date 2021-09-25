// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Problem Link : https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

int solve(TreeNode* root,int &ans){
    if(!root)
        return 0;
    int l=solve(root->left,ans);
    int r=solve(root->right,ans);
    int leftPath=root->val+l;  // Considering left Path
    int rightPath=root->val+r;  // Considering right Path
    int fullPath=root->val+l+r;  // Considering root int the path
    ans=max({ans,root->val,leftPath,rightPath,fullPath}); 
    return max(max(leftPath,rightPath),root->val);
}

int Solution::maxPathSum(TreeNode* root) {
    int ans=INT_MIN;
    solve(root,ans);
    return ans;
}
