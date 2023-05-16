/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       
        //recursive
        
        // if(head==NULL || head->next==NULL) return head;
        // ListNode*temp=head->next;
        // head->next=temp->next;
        // temp->next=head;
        // head->next=swapPairs(head->next);
        // return temp;
        
        //iterative
        
        if(!head || !head->next) return head;
        ListNode*newHead=head->next;
        ListNode*prev=NULL;
        while(head && head->next){
            ListNode*temp=head->next;
            head->next=temp->next;
            temp->next=head;
            if(prev) prev->next=temp;
            prev=temp->next;
            head=head->next;
        }
        return newHead;
    }
};