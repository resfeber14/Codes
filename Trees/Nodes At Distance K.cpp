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

void printAtLevelK(node* root,int k){
	if(!root)
		return;
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}

int printNodesAtDistanceK(node* root,node* target,int k){
	if(!root){
		return -1;
	}
	//if we have found target
	if(root==target){
		printAtLevelK(root,k);
		return 0;
	}

	//if we haven't found target
	int DL=printNodesAtDistanceK(root->left,target,k);
	if(DL!=-1){
		if(DL+1==k){
			cout<<root->data;
		}
		else{
			printAtLevelK(root->right,k-2-DL);
		}
		return 1+DL:
	}
	int DR=printNodesAtDistanceK(root->right,target,k);
	if(DR!=-1){
		if(DR+1==k){
			cout<<root->data;
		}
		else{
			printAtLevelK(root->left,k-2-DR);
		}
		return 1+DR;
	}
	return -1;
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root=buildTree();
    return 0;
}
