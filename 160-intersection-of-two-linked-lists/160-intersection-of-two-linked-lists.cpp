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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set< ListNode* > s;
            
        if ( headA == headB ){
            return headA;
        }
        
        for(ListNode* temp = headA ; temp != NULL ; temp = temp->next){
            s.insert(temp);
        }
        
        for( ListNode* temp = headB ; temp != NULL ; temp = temp->next ){
            int isize = s.size();
            s.insert(temp);
            
            if ( isize == s.size()){
                return temp;
            }
        }
        
        return NULL;
    }
};