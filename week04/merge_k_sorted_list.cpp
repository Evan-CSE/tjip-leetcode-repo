/*
    TC: O(k*n)
    where,
         k is the length of the vector of lists
         n is the total number of elements in the final list
*/
class Solution
{
public:
    ListNode *merge_sorted_list(ListNode *left, ListNode *right)
    {
        ListNode *dummy_head = new ListNode(0);
        ListNode *current_node = dummy_head;
        auto newNode = dummy_head;
        while (left and right)
        {
            if (left->val <= right->val)
            {
                newNode = left;
                left = left->next;
            }
            else
            {
                newNode = right;
                right = right->next;
            }
            current_node->next = newNode;
            current_node = newNode;
        }
        while (left)
        {
            current_node->next = left;
            current_node = left;
            left = left->next;
        }
        while (right)
        {
            current_node->next = right;
            current_node = right;
            right = right->next;
        }
        return dummy_head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        ListNode *dummy_head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            dummy_head = merge_sorted_list(dummy_head, lists[i]);
        }
        return dummy_head;
    }
};