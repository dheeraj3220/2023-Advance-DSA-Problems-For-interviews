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
    ListNode* findMiddleNode(ListNode*t){
        ListNode*head=t;
        if(!head || !head->next) return head;
        ListNode*slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode*head){
        if(!head || !head->next) return head;
        ListNode*ans=reverse(head->next);
        cout<<head->val;
        head->next->next=head;
        head->next=NULL;
        return ans;
    }
        
    int pairSum(ListNode* head) {
        ListNode*mid=findMiddleNode(head);
        ListNode*newHead=mid->next;
        mid->next=NULL;
        ListNode*revHead=reverse(newHead);
        int maxSum=0;
        while(head!=NULL && newHead!=NULL){
            maxSum=max(maxSum,(head->val+revHead->val));
            cout<<head->val <<" "<<revHead->val<<endl;
            head=head->next;
            revHead=revHead->next;
            
        }
        return maxSum; 
    }
};