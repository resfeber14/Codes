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

int height(node* root){
	if(!root)
		return 0;
	int h1=height(root->left);
	int h2=height(root->right);
	return max(h1,h2)+1;
}

int diameter(node* root){
	if(!root){
		return 0;
	}
	int D1=height(root->left)+height(root->right);
	int D2=diameter(root->left);
	int D3=diameter(root->right);
	return max({D1,D2,D3});
}



int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root=buildTree();
    cout<<diameter(root)<<"\n";
    return 0;
}


















