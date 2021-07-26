// Problem Link:  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

TreeNode* solve(vector<int> &arr,int i,int j){
        if(i>j)
            return NULL;
        int mid=(i+j)>>1;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve(arr,i,mid-1);
        root->right=solve(arr,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        return solve(arr,i,j);
    }
