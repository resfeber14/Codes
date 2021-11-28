// We will divide the array into two subsets.Initially,elements till index 0 will be the sorted half
// as the array containing 1 element will always be considered as sorted and all other elements are
// a part of unsorted subset.Now ,we will keep picking elements from the unsorted subset and keep
// inserting it in the sorted subset
// Pick an element from the sorted part,and shift all the elements of the sorted half to the right which 
// are greater than it

// Time complexity: Best case: When array is already sorted, O(N)
// Average case: O(N*N)
// Worst Case: O(n*n) When array is reversely sorted
// No. of comparisons are less,so it is considered to be better than Insertion sort and Bubble sort 

void insertion_sort(vector<int> &v,int n){
	for(int i=1;i<n;i++){
		int val=v[i];
		int hole=i;
		while(hole>0 && val<v[hole-1]){
			v[hole]=v[hole-1];
			hole--;
		}
		v[hole]=val;
	}
}
