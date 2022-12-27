/**
 * TC: O(n)
 * MC:O(1)
 * where n is the number of elements in the list
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast;
        ListNode *slow;
        fast = head;
        slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};