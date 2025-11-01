class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> delete_set(nums.begin(), nums.end());

        ListNode dummy;
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != nullptr) {
            int next_val = current->next->val;

            if (delete_set.count(next_val)) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return dummy.next;
    }
};
