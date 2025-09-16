class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while(curr && curr->next){
            ListNode *first = curr;
            ListNode *second = curr->next;

            prev->next=second;
            first->next=second->next;
            second->next=first;

            prev=first;
            curr=first->next;
        }
        return dummy->next;
    }
};
