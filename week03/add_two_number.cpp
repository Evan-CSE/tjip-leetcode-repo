/**
 * TC: O(n)
 * MC: O(n)
 * where n is the maximum number of elements between both of the lists
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy_head = new ListNode(0);
        ListNode *current_node = dummy_head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int first_digit = l1 ? l1->val : 0;
            int second_digit = l2 ? l2->val : 0;
            int sum = first_digit + second_digit + carry;
            carry = sum / 10;
            sum %= 10;
            current_node->next = new ListNode(sum, NULL);
            current_node = current_node->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy_head->next;
    }
};