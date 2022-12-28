/**
 * TC: O(n)
 * MC:O(1)
 * where n is the number of elements in list
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto fast = head;
        ListNode *dummy_node = new ListNode(0, head);
        auto slow = dummy_node;
        int displacement = 0;
        while (displacement < n)
            fast = fast->next, displacement++;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete (fast);
        return dummy_node->next;
    }
};