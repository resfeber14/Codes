/*
Problem Link: https://binarysearch.com/problems/Subtree-with-Maximum-Average
*/

pair<int,int> solve1(Tree* root){ // returns a pair which contains {total sum of the subtree starting from root , no of nodes in the subtree of root}
    pair<int,int> p={0,0};
    if(!root){
        p.first=0;
        p.second=0;
        return p;
    }
    auto l=solve1(root->left);
    auto r=solve1(root->right);
    p.first=l.first+r.first+root->val;
    p.second=1+l.second+r.second;
    return p;
}

double solve(Tree* root) {
    if(!root)
        return 0.0;
    pair<int,int> p=solve1(root);
    double ans= double(p.first)/double(p.second);
    return ans= max(max(solve(root->left),solve(root->right)),ans);
}
