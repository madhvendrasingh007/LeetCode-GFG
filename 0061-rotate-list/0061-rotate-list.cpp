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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=head;
        ListNode *prev=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        for(int i=0;i<k;i++){
            prev=head;
            while(prev->next->next!=NULL){
                prev=prev->next;
            }
            temp=prev->next;
                prev->next=NULL;
                temp->next=head;
                head=temp;
        }
        return head;
    }
};