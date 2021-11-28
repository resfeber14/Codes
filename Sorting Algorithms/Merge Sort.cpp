// Stable,Not Inplace
// Worst Case : O(N*logN)
// Space Complexity: O(N)

void merge(int l,int mid,int r,vector<int> &v,int n){
	int n1=mid-l+1;
	int n2= r-mid;
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++){
		arr1[i]=v[i+l];
	}
	for(int i=0;i<n2;i++){
		arr2[i]=v[i+mid+1];
	}
	int indexMerged=l,left=0,right=0;
	while(left<n1 && right<n2){
		if(arr1[left]<=arr2[right]){
			v[indexMerged]=arr1[left];
			left++;
			indexMerged++;
		}
		else{
			v[indexMerged]=arr2[right];
			right++;
			indexMerged++;
		}
	}
	while(left<n1){
		v[indexMerged]=arr1[left];
		left++;
		indexMerged++;
	}
	while(right<n2){
		v[indexMerged]=arr2[right];
		right++;
		indexMerged++;
	}
	
}

void merge_sort(int l,int r,vector<int> &v,int n){
	if(l>=r){
		return;
	}
	int mid=(l+ (r-l)/2);
	merge_sort(l,mid,v,n);
	merge_sort(mid+1,r,v,n);
	merge(l,mid,r,v,n);
}
