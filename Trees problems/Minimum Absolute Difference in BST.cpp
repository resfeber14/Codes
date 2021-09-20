// Problem Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// Approach: Time Complexity: O(N), Space Complexity: O(1)

// As we know the Inorder traversal gives the sorted order in a BST
// If we do inorder traversal and store in a variable which node we had last visited,then we can get the ans.


 void solve(TreeNode* root,TreeNode* &prev,int &ans){
        if(!root)
            return ;
        solve(root->left,prev,ans);
        if(prev){
            ans=min(ans,abs(prev->val-root->val));
        }
        prev=root;
        solve(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;
        int ans=INT_MAX;
        solve(root,prev,ans);
        return ans;
    }
