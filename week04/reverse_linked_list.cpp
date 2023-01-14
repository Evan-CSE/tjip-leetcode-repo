/**
 * TC: O(n)
 * MC:O(1)
 * where n is the number of elements in the list
 */
class Solution
{
public:
    const static int DUMMY_VALUE = 0;
    ListNode *reverseList(ListNode *cur)
    {
        ListNode *nxt = new ListNode(DUMMY_VALUE, NULL);
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