// At any stage,left part will be unsorted and the right part will be sorted
// Time Complexity: O(N) for the best case(when the array is already sorted)
// Time Complexity: O(N*N) {For average and worst case complexity}
// Space Complexity:O(1)
void bubble_sort(vector<int> &v,int n){ // Stable Sort,Inplace,Bubble sort
	for(int i=1;i<n;i++){
		bool flag=false;
		for(int j=0;j<n-i;j++){
			if(v[j]>v[j+1]){
				flag=true;
				swap(v[j],v[j+1]);
			}
		}
		if(!flag)
			break;
	}
}
