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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len =1;
        ListNode*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        if(k>=len) k=k%len;
        len-=k;
        temp->next=head;
        temp=head;
        while(--len) temp=temp->next;
        ListNode*newHead=temp->next;
        temp->next=NULL;
        return newHead;
        
    }
};