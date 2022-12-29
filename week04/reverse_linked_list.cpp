/**
 * TC: O(n)
 * MC:O(1)
 * where n is the number of elements in the list
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *cur)
    {
        ListNode *nxt = new ListNode(0, NULL);
        ListNode *prev = NULL;
        while (cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};