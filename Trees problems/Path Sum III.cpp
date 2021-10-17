/*
Problem Link:  https://leetcode.com/problems/path-sum-iii/

*/


int solve(TreeNode* root,int k){
        if(!root)
            return 0;
        int l=0,r=0;
        int ans=0;
        if(k-root->val==0) // If by considering this node we have got the sum =targetSum,then there is a path ,hence ans++
            ans++;
        return ans+solve(root->left,k-root->val)+solve(root->right,k-root->val);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        int ans=0;
        ans= solve(root,targetSum); // No of paths we get starting from current node
        return ans+pathSum(root->left,targetSum)+pathSum(root->right,targetSum); // return the no of paths we get considering current node+ no of paths we get considering the left
      // node + no of paths we get considering the right node
    }
