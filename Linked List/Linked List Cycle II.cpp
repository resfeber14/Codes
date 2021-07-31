// Problem Link:  https://leetcode.com/problems/linked-list-cycle-ii/

//Method 1: Brute Force
// Time complexity: O(N)  Space Complexity: O(N)

ListNode *detectCycle(ListNode *root) {
        ListNode* head=root;
        map<ListNode*,int> m;
        while(head){
            if(m[head]==0)
                m[head]++;
            else
                return head;
            head=head->next;
        }
        return NULL;
    }

// Method 2:  Slow and fast Pointer

//Intuition: Firstly find whether a linked list contains cycle or not.If it contains,then keep a pointer at head of the node and move slow and entry pointer by step 1
// until they collide.the collision point will be the entry point of cycle
// Proof:  L1-> distance covered just before entering into cycle.  L2-> distance covered from entry to the collision point of fast and slow pointer.
// C-> length of cycle
// distance covered by Slow pointer = L1+L2
// distance covered by fast pointer= L1+L2+ n*C
// distance covered by fast pointer= 2*distance covered by slow pointer
// L1+L2+n*C= 2*(L1+L2)
// L1=n*C-L2 which is remaining part of cycle
//here L1 will be covered by entry pointer and n*C-L2 by slow pointer.Hence proved

// Time Complexity: O(N) Space Complexity: O(1)

ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
       if(!head || !head->next)
           return NULL;
        bool flag=false;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                flag=true;
                break;
            }
                
        }
        if(!flag)
            return NULL;
        ListNode* entry=head;
        while(entry!=slow){
            entry=entry->next;
            slow=slow->next;
        }
        return slow;
    }
