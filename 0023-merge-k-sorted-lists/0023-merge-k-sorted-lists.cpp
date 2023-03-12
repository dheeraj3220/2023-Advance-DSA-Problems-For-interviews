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
#define dt pair<int,ListNode*>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<dt,vector<dt>,greater<dt>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        ListNode*head=NULL;
        ListNode*curNode=NULL;
        while(!pq.empty()){
            ListNode* node = pq.top().second;
            if(curNode==NULL){
                head=node;
                curNode=node;
            }
            else{
                curNode->next=node;
                curNode=curNode->next;
            }
            pq.pop();
            if(node->next) pq.push({node->next->val,node->next});
        }
        return head;
        
    }
};