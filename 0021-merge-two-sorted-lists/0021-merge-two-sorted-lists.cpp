class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;


        if(l1->val > l2->val){  // taking L1 is smaller than l2 
            swap(l1,l2);    // haar baar l1 hi chota hoga
        }
        ListNode* result = l1;
        ListNode* temp = NULL;
        while(l1 != NULL && l2 != NULL){
            
            if(l1->val <= l2->val ){
                temp = l1;
                l1 = l1->next;
            }
            else {
                temp -> next = l2;
                swap(l1,l2); // haar baar l1 hi chota hoga
            }
        }
         while(l1 != NULL){
            temp->next = l1;
            temp = l1;
            l2 = l2->next;
        }
        while(l2 != NULL){
            temp->next = l2;
            temp = l2;
            l2 = l2 ->next;
        }
       
        return result;
    }
};