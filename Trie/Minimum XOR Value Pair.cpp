/*
Given an array of integers. Find the pair in an array that has a minimum XOR value. 
Examples : 
 

Input : arr[] =  {9, 5, 3}
Output : 6
        All pair with xor value (9 ^ 5) => 12, 
        (5 ^ 3) => 6, (9 ^ 3) => 10.
        Minimum XOR value is 6

Input : arr[] = {1, 2, 3, 4, 5}
Output : 1 

*/

/* Approach 1: Traverse the array by creating 2 loops and find the answer
Time Complexity: O(N*N) Space Complexity: O(1)

*/

/*
Approach 2: 
Sort the array and find the xor of the adjacent elmenets and take minimum among them
Time Complexity: O(N*logN) Space Complexity: O(1)

*/

/*
Approach 3: Trie
