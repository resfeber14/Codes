// Problem Link:  https://leetcode.com/problems/search-in-rotated-sorted-array/


// Here,compare left and right elements
// Case 1: If(arr[l]>arr[r])  It means array is rotated  So we need to check which half of the array is sorted
// For checking this, check if arr[mid]>=arr[l] then it means left half is sorted. Here we are not checking if right half is sorted or not bcoz there will be a case
// 3 4 5 1 2 Here we can't check if right half is sorted or not.
// Now if left half is sorted then check if k lies in l...mid or not.If yes, then r=mid-1 else l=mid+1
// If left half isn't sorted eg: 3 1 2 then right half will be sorted.so check if k lie in mid.... r ot not.If it does then l=mid+1 else r=mid-1

// Case 2: if(arr[r]>arr[l]) it means array is not rotated then it will be normally binary search
// check if k lie in right half or left half.coz in this case at any point of time both half will be sorted

// Time complexity: O(log(N))


int search(vector<int>& arr, int k) {
        int n=arr.size()-1;
        int l=0,r=n;
        while(l<=r){
            // 3 1
            int mid=(l+r)>>1;
            if(arr[mid]==k)
                return mid;
            if(arr[l]>arr[r]){
                if(arr[mid]>=arr[l]){
                    if(k>=arr[l] && k<arr[mid]){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else{
                    if(k>arr[mid] && k<=arr[r]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
            else{
                if(k<arr[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
