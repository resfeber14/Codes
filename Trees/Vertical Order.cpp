
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


int levelOrderPrint(node* root,int k,map<int,vector<int> > &m){
	if(!root)
		return;
	m[k].push_back(root->data);
	levelOrderPrint(root->left,k-1,m);
	levelOrderPrint(root->right,k+1,m);
}

int levelOrder(node* root){
	map<int,vector<int> > m;
	int d=0;
	levelOrderPrint(root,d,m);
	for(auto it:m){
		for(auto val:it.second){
			cout<<val<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root=buildTree();
    levelOrder(root);
    return 0;
}

