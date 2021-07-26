// Method 1:  Time Complexity: O(N*N) Space Complexity: O(1)

//Model the solution using graphs. Initialize indegree and outdegree of every vertex as 0. 
//If A knows B, draw a directed edge from A to B, increase indegree of B and outdegree of A by 1. 
//Construct all possible edges of the graph for every possible pair [i, j]. There are NC2 pairs. If a celebrity is present in the party,
//there will be one sink node in the graph with outdegree of zero and indegree of N-1. 

int celebrity(vector<vector<int> >& arr, int n) {   
        int indegree[n],outdegree[n];
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(outdegree));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]){
                    indegree[j]++;
                    outdegree[i]++;
                }
            }
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }
        return -1;
    }





// Method 2: Time complexity: O(N) Space Complexity: O(1) Using stack
// Create a stack and push all the id’s in the stack.
//Run a loop while there are more than 1 element in the stack.
//Pop top two element from the stack (represent them as A and B)
//If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
//Assign the remaining element in the stack as the celebrity.
//Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. 
//if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.

int celebrity(vector<vector<int> >& arr, int n){
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            if(arr[x][y] && arr[y][x]==0){
                s.push(y);
            }
            else if(arr[y][x] && arr[x][y]==0){
                s.push(x);
            }
        }
        if(s.empty())
        return -1;
        int x=s.top();        
        bool flag=true;
        for(int i=0;i<n;i++){
            if(i!=x){
                if(arr[x][i] || !arr[i][x]){
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag)
            return x;
        return -1;
    }

// Method 3: Time Complexity: O(N) Space Complexity: O(1) Two Pointer approach
//The idea is to use two pointers, one from start and one from the end. Assume the start person is A, and the end person is B. If A knows B, then A must not be the celebrity. 
//Else, B must not be the celebrity. At the end of the loop, only one index will be left as a celebrity. Go through each person again and check whether this is the celebrity. 
//The Two Pointer approach can be used where two pointers can be assigned, one at the start and the other at the end, and the elements can be compared and the search space
//can be reduced. 

int celebrity(vector<vector<int> >& arr, int n){
        int x=0,y=n-1;
        while(x<y){
            if(arr[x][y]){
                x++;
            }
            else{
                y--;
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(i!=x){
                if(arr[x][i] || !arr[i][x]){
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag)
            return x;
        return -1;
    }
