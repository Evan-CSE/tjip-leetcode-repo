/**
 * TC: O(n)
 * MC: O(n)
 * where n is the number of elements in the list
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *current_head)
    {
        ListNode *prev = NULL;
        ListNode *current_node;
        while (current_head)
        {
            current_node = current_head;
            current_head = current_head->next;
            current_node->next = prev;
            prev = current_node;
        }
        return prev;
    }
    int pairSum(ListNode *head)
    {
        auto fast = head;
        ListNode *dummy_node = new ListNode(-1, head);
        auto slow = dummy_node;
        int max_sum = 0;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Now slow is in the middle of the list
        // now reverese the list from this point
        auto prev = reverseList(slow->next);
        slow = head;
        fast = prev;
        while (prev)
        {
            max_sum = max(max_sum, slow->val + prev->val);
            prev = prev->next;
            slow = slow->next;
        }
        // revert the list to its original form
        reverseList(fast);
        return max_sum;
    }
};