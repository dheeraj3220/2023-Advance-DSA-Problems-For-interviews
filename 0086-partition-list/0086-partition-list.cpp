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
    ListNode* partition(ListNode* head, int x) {
        ListNode*left=new ListNode(0);
        ListNode*right=new ListNode(0);
        ListNode*ls=left;
        ListNode*rs=right;
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                left->next=temp;
                left=temp;
            }
            else{
                right->next=temp;
                right=temp;
            }
            temp=temp->next;
        }
        left->next=rs->next;
        right->next=NULL;
        return ls->next;
        
    }
};