// Problem Link :  https://leetcode.com/problems/merge-two-binary-trees/


//Method 1:

TreeNode* solve(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)
            return NULL;
        int curr=0;
        if(root1)
            curr+=root1->val;
        if(root2)
            curr+=root2->val;
        TreeNode* root=new TreeNode(curr);
        if(root1 && root2)
            root->left=solve(root1->left,root2->left);
        else if(root1 && !root2)
            root->left=solve(root1->left,root2);
        else if(!root1 && root2)
            root->left=solve(root1,root2->left);
        if(root1 && root2)
            root->right=solve(root1->right,root2->right);
        else if(root1 && !root2)
            root->right=solve(root1->right,root2);
        else if(!root1 && root2)
            root->right=solve(root1,root2->right);
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
        //return root1;
    }


// Method 2:

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL){
            return t2;
        }
        if(t2==NULL){
            return t1;
        }
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        t1->val=t1->val+t2->val;
        return t1;
    }
