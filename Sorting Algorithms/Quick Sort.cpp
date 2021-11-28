int partition(vector<int> &arr,int l,int r){
	int pivot=arr[r];
	int pIndex=l;
	for(int i=l;i<r;i++){
		if(arr[i]<=pivot){
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex],arr[r]);
	return pIndex;
}

void quick_sort(vector<int> &arr,int l,int r){
	if(l>=r){
		return;
	}
	int pIndex=partition(arr,l,r);
	quick_sort(arr,l,pIndex-1);
	quick_sort(arr,pIndex+1,r);
}
