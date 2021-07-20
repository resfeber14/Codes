// The problem in the naive approach was that we were calculating height for each node without memomising it.
// So,now instead of returning one value,which was diameter earlier,we will return two values,i.e. diameter and height of a each node.
// This way we don't need to recalculate the height of a particular node each time.

//Time Complexity: O(N)

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

HDPair OptimisedDia(node* root){
	HDPair p;
	if(!root){
		p.height=0;
		p.diameter=0;
		return p;
	}
	HDPair Left=OptimisedDia(root->left);
	HDPair Right=OptimisedDia(root->right);
	p.height=max(Left.height,Right.height)+1;
	
	int D1=Left.height+Right.height;
	int D2=Left.diameter;
	int D3=Right.diameter;
	p.diameter=max({D1,D2,D3});
	return p;
}


int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root=buildTree();
    cout<<OptimisedDia(root).diameter<<"\n";
    return 0;
}
