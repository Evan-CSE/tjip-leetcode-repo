/**
 * TC: O(n)
 * MC:O(1)
 * where n is the number of elements in list
 */
class Solution
{
public:
    int determineSize(ListNode *head)
    {
        int size = 0;
        ListNode *current_node = new ListNode(INT_MAX, NULL);
        current_node->next = head;
        current_node = current_node->next;
        while (current_node)
            current_node = current_node->next, size++;
        return size;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size_of_list = determineSize(head);
        n = size_of_list - n;
        ListNode *current_node_head = new ListNode(INT_MAX, NULL);
        current_node_head->next = head;
        ListNode *node = current_node_head;
        while (n--)
            node = node->next;
        ListNode *del_node;
        del_node = node->next;
        node->next = node->next->next;
        delete (del_node);
        return current_node_head->next;
    }
};