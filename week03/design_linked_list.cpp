/**
 * TC: O(n)
 * MC: O(n)
 * where n is the number of elements of the list
 */

class MyLinkedList
{
public:
    class Node
    {
    public:
        int value;
        Node *next;
        Node(int val, Node *nxt)
        {
            value = val;
            next = nxt;
        }
    };
    int len;
    Node *head;
    MyLinkedList()
    {
        head = new Node(INT_MIN, NULL);
        len = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= len)
            return -1;
        Node *current_node = head->next;
        while (index--)
            current_node = current_node->next;
        return current_node->value;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;
        Node *current_node = head;
        while (index--)
            current_node = current_node->next;
        Node *new_node = new Node(val, current_node->next);
        current_node->next = new_node;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;
        Node *current_node = head;
        while (index--)
            current_node = current_node->next;
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        len--;
        delete (delete_node);
    }
};
