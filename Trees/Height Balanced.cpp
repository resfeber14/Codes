// Given a Binary Tree ,check if it height balanced or not.
// A non-empty tree is height balanced if:
// 1) Left subtree of T is balanced
// 2) Right subtree of T is balanced
// 3) The difference between heights of left subtree and right subtree is not more than 1.

//Time Complexity: O(N)

#include <bits/stdc++.h> 
#include<map>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ppi pair<int,int>
#define ppl pair<long long int,long long int>
#define f first
#define s second

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

class node{
public:
	int data;
	node* left;
	node *right;
	node(int d){
		data =d;
		left=NULL;
		right=NULL;
	}
};

//1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node* n= new node(d);
	n->left=buildTree();
	n->right=buildTree();
	return n;
}

pair<int,bool> isHeightBalanced(node* root){
	pair<int,bool> p;
	if(!root){
		p.first=0; //denotes height
		p.second=true //denotes balanced or not
		return p;
	}
	pair<int,bool> Left=isHeightBalanced(root->left);
	pair<int,bool> Right=isHeightBalanced(root->right);
	int height=max(Left.first,Right.first)+1;
	if(abs(Left.first-Right.first)<=1 && Left.second && Right.second){
		return make_pair(height,true);
	}
	return make_pair(height,false);
	
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root=buildTree();
    if(isHeightBalanced(root)){
        cout<<"A Height Balanced tree\n";
    }
    else{
        cout<<"Not a Height Balanced tree\n";
    }
    return 0;
}
