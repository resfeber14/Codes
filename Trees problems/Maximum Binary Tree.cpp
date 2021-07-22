// Problem Link:  https://leetcode.com/problems/maximum-binary-tree/

TreeNode* solve(vector<int> &arr,int i,int j){
        if(i>j)
            return NULL;
        int ind=-1;
        int maxx=INT_MIN;
        for(int k=i;k<=j;k++){
            if(arr[k]>maxx){
                maxx=arr[k];
                ind=k;
            }
        }
        TreeNode* root=new TreeNode(arr[ind]);
        root->left=solve(arr,i,ind-1);
        root->right=solve(arr,ind+1,j);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,0,n-1);
    }
