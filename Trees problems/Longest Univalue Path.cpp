/*
Problem Link: https://leetcode.com/problems/longest-univalue-path/

*/
// Time complexity: O(N*N) Space Complexity: O(1)


int solve(TreeNode* root,int &ans){
        if(!root)
            return 0;
        int cnt1=0,cnt2=0;
        if(root->left && root->left->val==root->val)
            cnt1+=solve(root->left,ans);
        if(root->right && root->right->val==root->val)
            cnt2+=solve(root->right,ans);
        int op1=cnt1+cnt2+1; // if the path passes through the root
        int op2=cnt1+1; // if the path lies in the left 
        int op3=cnt2+1; // if the path lies in the left 
        ans=max({op1,op2,op3,ans}); 
        int x=max(op2,op3); // take maximum of two paths
        return x;
    }
    
    void solve1(TreeNode* root,int &ans){
        if(!root)
            return;
        solve(root,ans);
        solve1(root->left,ans);
        solve1(root->right,ans);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        solve1(root,ans);
        if(ans>0) // we want no of edges not no of nodes.
            ans--;
        return ans;
    }

/*
Approach 2: Time complexity: O(N) Space Complexity: O(1)

*/

    int ans=0;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(!root->left || root->left->val!=root->val)
            l=0;
        if(!root->right || root->right->val !=root->val)
            r=0;
        ans=max(ans,l+r);
        return max(l+1,r+1);
    }
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        if(!root)
            return 0;
        dfs(root);
        return ans;
    }
