/* 
Problem Link: https://leetcode.com/problems/reach-a-number/

Step 0: Get positive target value (step to get negative target is the same as to get positive value due to symmetry).
Step 1: Find the smallest step that the summation from 1 to step just exceeds or equalstarget.
Step 2: Find the difference between sum and target. The goal is to get rid of the difference to reach target. For ith move, if we switch the right move to the left, the change in summation will be 2*i less. Now the difference between sum and target has to be an even number in order for the math to check out.
Step 2.1: If the difference value is even, we can return the current step.
Step 2.2: If the difference value is odd, we need to increase the step until the difference is even (at most 2 more steps needed).
Eg:
target = 5
Step 0: target = 5.
Step 1: sum = 1 + 2 + 3 = 6 > 5, step = 3.
Step 2: Difference = 6 - 5 = 1. Since the difference is an odd value, we will not reach the target by switching any right move to the left. So we increase our step.
Step 2.2: We need to increase step by 2 to get an even difference (i.e. 1 + 2 + 3 + 4 + 5 = 15, now step = 5, difference = 15 - 5 = 10). Now that we have an even difference, we can simply switch any move to the left (i.e. change + to -) as long as the summation of the changed value equals to half of the difference. We can switch 1 and 4 or 2 and 3 or 5.

*/



int reachNumber(int n) {
        int steps=0,curr=0;
        n=abs(n);
        while(curr<n){
            steps++;
            curr+=steps;
        }
        while(((curr-n)%2)!=0){
            steps++;
            curr+=steps;
        }
        return steps;
    }
};
