// Problem Link:  https://leetcode.com/problems/most-frequent-subtree-sum/

// Time Complexity: O(N) Space Complexity: O(N)

// We store the subtree sum of each node by firstly making a postorder traversal ans store the frequency in a map

int solve(TreeNode* root,int &ans,map<int,int> &m){
        if(!root)
            return INT_MAX;
        int l=solve(root->left,ans,m);
        int r=solve(root->right,ans,m);
        if(l==INT_MAX)
            l=0;
        if(r==INT_MAX)
            r=0;
        m[l+r+root->val]++;
        ans=max(ans,m[l+r+root->val]);
        return l+r+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxx=0;
        map<int,int> m;
        solve(root,maxx,m);
        vector<int> v;
        for(auto it: m){
            if(it.second==maxx)
                v.push_back(it.first);
        }
        return v;
    }
