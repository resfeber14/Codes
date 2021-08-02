// Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

void printRightView(Node* root,vector<int> &v){
        if(!root)
            return;
        if(root->right){
            printRightView(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left){
            printRightView(root->left,v);
            v.push_back(root->data);
        }
    }
    void printLeaves(Node* root,vector<int> &v){
        if(!root)
            return;
        printLeaves(root->left,v);
        if(!root->left && !root->right)
            v.push_back(root->data);
        printLeaves(root->right,v);
    }
    void printLeftView(Node* root,vector<int> &v){
        if(!root)
            return;
        if(root->left){
            v.push_back(root->data);
            printLeftView(root->left,v);
        }
        else if(root->right){
            v.push_back(root->data);
            printLeftView(root->right,v);
        }
    }
    void solve(Node* root,vector<int> &v){
        if(!root)
            return;
        v.push_back(root->data);
        printLeftView(root->left,v);
        printLeaves(root->left,v);
        printLeaves(root->right,v);
        printRightView(root->right,v);
    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> v;
        solve(root,v);
        return v;
    }
