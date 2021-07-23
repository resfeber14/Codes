
//Problem Link:   https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// Method 1:DFS
void solve(Node* root,int d,vector<int> &v){
    if(!root)
        return;
    if(v.size()<d){
        v.push_back(root->data);
    }
    solve(root->left,d+1,v);
    solve(root->right,d+1,v);
}
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> v;
    solve(root,1,v);
    return v;
}

// Method 2:BFS


vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> v;
   if(!root)
   return v;
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   v.push_back(root->data);
   while(!q.empty()){
       Node* curr=q.front();
       q.pop();
       if(curr){
           if(curr->left)
                q.push(curr->left);
            if(curr->right){
                q.push(curr->right);
            }
       }
       else{
           if(!q.empty()){
               q.push(NULL);
               v.push_back(q.front()->data);
           }
       }
   }
   return v;
}
