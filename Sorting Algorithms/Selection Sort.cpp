// Approach: In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

// Time Complexity: O(N*N) Space Complexity: O(1)
// not stable

void selection_sort(vector<int> &v){
	int n=v.size();
	for(int i=0;i<n-1;i++){
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(v[j]<v[minIndex]){
				minIndex=j;
			}
		}
		swap(v[minIndex],v[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }
    selection_sort(v);
    for(int i=0;i<n;i++){
    	cout<<v[i]<<" ";
    }
    
    
    return 0;
}
