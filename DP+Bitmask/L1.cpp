// Problem: There is a vector with values from 1 to N



void insert(int &subset,int x){  // insert x from the array
	subset=subset ^ (1<<(x-1));
}

void remove(int &subset,int x){ // removes x from the array
	subset=subset ^ (1<<(x-1));
}

void display(int num){  // display which elements are present in the array
	for(int i=0;i<=31;i++){
		if(((1<<i) & num)!=0){
			cout<<i+1<<" ";
		}
	}
	cout<<"\n";
}

int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int set=2;  // Here we are considering that there is a vector and if its some position is 1 then pos+1 element is present in that set
  	display(set);
  	remove(set,2);
  	insert(set,5);
  	display(set);
  	
    return 0;
}
