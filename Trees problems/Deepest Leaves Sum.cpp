// Problem Link:  https://leetcode.com/problems/deepest-leaves-sum/

// Method 1: DFS

void solve(TreeNode* root,int l,int &lev,int &ans){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(l==lev)
                ans+=root->val;
            else if(l>lev){
                lev=l;
                ans=root->val;
            }
        }
        solve(root->left,l+1,lev,ans);
        solve(root->right,l+1,lev,ans);
    }
    int deepestLeavesSum(TreeNode* root) {
        int lev=0;
        int ans=0;
        solve(root,0,lev,ans);
        return ans;
    }

// Method 2: BFS


int sum=0;
    int solve(TreeNode* root,int depth,int &d){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            if(d==depth){
                sum+=root->val;
            }
            else if(d>depth){
                return 0;
            }
            else{
                sum=root->val;
                d=depth;
            }
        }
        solve(root->left,depth+1,d);
        solve(root->right,depth+1,d);
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int d=0;
        return solve(root,0,d);
    }
