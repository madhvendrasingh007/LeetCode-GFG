/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode*newNode=new ListNode;
                newNode=head;
                while(newNode!=slow){
                    newNode=newNode->next;
                    slow=slow->next;
                }
                return newNode;
            }
        }
        return NULL;
    }
};