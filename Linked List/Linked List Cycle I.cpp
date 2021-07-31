// Problem Link:    https://leetcode.com/problems/linked-list-cycle/

//Method 1: Brute force 
// Time Complexity: O(N) Space Complexity: O(N)

bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        while(head){
            if(m[head]==0)
                m[head]++;
            else
                return true;
            head=head->next;
        }
        return false;
    }


// Method 2: slow and Fast Pointer
// Time Complexity: O(N) Space Complexity: O(1)

//  a->  b  ->   c
// slow  fast      
// Here if the Linked list contains cycle every case will be reduced to above.Hence we can use the slow and fast pointer approach

bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }


