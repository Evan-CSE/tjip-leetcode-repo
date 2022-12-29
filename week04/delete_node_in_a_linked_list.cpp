/**
 * TC: O(1)
 * MC: O(1)
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *new_node = node->next;
        node->val = new_node->val;
        node->next = new_node->next;
        delete (new_node);
    }
};