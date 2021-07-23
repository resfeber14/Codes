// Method1 : DFS-O(N) Space: O(N)+O(N)

void dfs(TreeNode* root,int par[],int parent,int dep[]){
        dep[root->val]=dep[parent]+1;
        par[root->val]=parent;
       // cout<<"Hi ";
        if(root->left)
            dfs(root->left,par,root->val,dep);
        if(root->right)
            dfs(root->right,par,root->val,dep);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int par[101],dep[101];
        memset(par,0,sizeof(par));
        memset(par,0,sizeof(dep));
        dfs(root,par,0,dep);
        return dep[x]==dep[y] && par[x]!=par[y];
        
    }

// Method 2: BFS- O(N)   Space: O(2^h)

 bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        bool flag1=false,flag2=false;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr){
                if(curr->val==x)
                flag1=true;
            if(curr->val==y)
                flag2=true;
            if(curr->left && curr->right){
                if(curr->left->val == x && curr->right->val==y || curr->left->val == y && curr->right->val==x)
                    return false;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
            else{
                if(flag1 && flag2)
                    return true;
                if(flag1 && !flag2 || !flag1 && flag2)
                    return false;
                
                if(!q.empty())
                    q.push(NULL);
            }
            
        }
        return false;
    }
