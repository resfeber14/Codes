// Problem Link:  https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Here we keep a minn maxx variable to know if a node can be attached to the root or not

TreeNode* solve(int &i,vector<int> &arr,int minn,int maxx){
        if(i==arr.size())
            return NULL;
        TreeNode* root=new TreeNode(arr[i]);
        if(minn<arr[i] && maxx>arr[i]){    // satisfying the criteria of the BST
            i++;
            root->left=solve(i,arr,minn,root->val);
            root->right=solve(i,arr,root->val,maxx);
            return root;
        }
       return NULL;  // Not satisfying the criteria 
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i=0;
        return solve(i,arr,INT_MIN,INT_MAX);
    }

// Modified version of the above question

// Problem Link: https://www.interviewbit.com/problems/valid-bst-from-preorder/

void solve1(int &i,vector<int> &arr,int minn,int maxx){
        if(i==arr.size())  // If all the nodes didn't get attach to the tree It's not a valid Preorder to construct a BST
            return ;
        if(minn<=arr[i] && maxx>=arr[i]){
            i++;
            solve1(i,arr,minn,arr[i-1]);
            solve1(i,arr,arr[i-1],maxx);
            return;
        }
       return;
    }
int Solution::solve(vector<int> &arr) {
    int i=0;
    solve1(i,arr,INT_MIN,INT_MAX);
    return i>=arr.size();
}
