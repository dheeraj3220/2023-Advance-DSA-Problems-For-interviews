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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode*temp=head;
        while(temp!=NULL){
            if(stk.empty() || stk.top()->val>=temp->val){
                stk.push(temp);
                temp=temp->next;
            }
            else{
                stk.pop();
            }
        }
        ListNode*cur=NULL;
        while(!stk.empty()){
            stk.top()->next=cur;
            cur=stk.top();
            stk.pop();
        }
        return cur;
    }
};