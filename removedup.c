/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // 1. Base case: empty list or single node
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* current = head;

    // 2. Traverse the list
    while (current != NULL && current->next != NULL) {
        // If current value is same as next, skip the next node
        if (current->val == current->next->val) {
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            // In a real environment, you'd call free(duplicate) here
        } else {
            // Otherwise, move to the next node
            current = current->next;
        }
    }

    return head;
}
