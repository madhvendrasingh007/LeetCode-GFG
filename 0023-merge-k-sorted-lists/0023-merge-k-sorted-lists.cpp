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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mergeKListsHelper(lists, 0, lists.size()-1);
    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if(start>end) return NULL; 
        if(start==end) return lists[start];

        int mid = start + (end-start)/2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1Head, ListNode* list2Head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        while(list1Head!=NULL && list2Head!=NULL){
            if(list1Head->val < list2Head->val){
                dummyTail->next = list1Head;
                list1Head = list1Head->next;
            }else{
                dummyTail->next = list2Head;
                list2Head = list2Head->next;
            }
            dummyTail = dummyTail->next;
        }
        dummyTail->next = (list1Head != NULL) ? list1Head : list2Head;
        return dummyHead->next;
    }
};