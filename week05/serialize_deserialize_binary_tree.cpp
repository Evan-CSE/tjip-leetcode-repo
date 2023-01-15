/**
 * @brief
 *  TC: O(n)
 *  MC: O(n)
 *  where 'n' is number of nodes of the tree. This is an overall complexity.
 */
class Codec
{
public:
    int indx = 0;
    vector<string> node_values;
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "#";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right + ",";
    }

    TreeNode *construct_node()
    {
        if (indx >= node_values.size() || node_values[indx] == "#")
        {
            return NULL;
        }
        TreeNode *new_node = new TreeNode(stoi(node_values[indx]));
        indx++;
        new_node->left = construct_node();
        indx++;
        new_node->right = construct_node();
        return new_node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string item;
        while (getline(ss, item, ','))
        {
            if (!item.empty())
                node_values.push_back(item);
        }
        return construct_node();
    }
};
