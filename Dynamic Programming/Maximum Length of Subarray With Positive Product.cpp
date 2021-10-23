/*
Problem Link: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

It's a basic dynamic programming problem. We should track a maximum length of subarray with a positive product and a maximum length of subarray with a negative product and at each step, we update our new max length.
There are 3 possible variants at each step:

arr[i] == 0 => means that our current subarray ends at this point, because if we multiply anything by 0 then the product will be equal to 0
arr[i] > 0 => means that we should increase the length of subarray with the positive product and if we had the negative product we increase that too
arr[i] < 0 => means that we can create the positive product from negative and vice versa, so at this step our max length with positive product equal to max length 
with the negative product that we had +1(if we had one), and our max length of subarray with negative product equal to the max length of subarray with positive product +1;

*/
int getMaxLen(vector<int>& arr) {
        int ind1=-1,ind2=-1,pos=0,neg=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                pos++;
                if(neg)
                    neg++;
            }
            else if(arr[i]<0){
                int temp=pos;
                if(neg>0)
                    pos=neg+1;
                else
                    pos=0;
                neg=temp+1;
            }
            else{
                pos=0,neg=0;
            }
            ans=max(ans,pos);
        }
        return ans;
    }
