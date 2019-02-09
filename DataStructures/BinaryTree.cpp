#include <iostream>

struct Node 
{
    int val;
    Node *small = NULL;
    Node *big = NULL;
};

class BinaryTree
{
    Node *head;
public:
    BinaryTree(): head {NULL}
    {}

    void Push(int val)
    {
        Node *temp = new Node;
        temp->val = val;
        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *current = head;
        while(true)
        {
            if (val < current->val) // go left
            {
                if (current->small == NULL) // assign new leaf node here
                {
                    current->small = temp;
                    break;
                }
                else
                    current = current->small; // move to next node to the left
            }
            else // go right
            {
                if (current->big == NULL) // assign new leaf node here
                {
                    current->big = temp;
                    break;
                }
                else
                    current = current->big; // move to next node to the right
            }
        }
    }

    void InOrderTraversal(Node *current)
    {
        bool firstCall = false;
        if (current == NULL)
        {
            firstCall = true;
            current = head;
        }
        // check left node
        if (current->small)
            InOrderTraversal(current->small);
        // print current node
        std::cout << current->val << " ";
        // check right node
        if (current->big)
            InOrderTraversal(current->big);
        if (firstCall)
            std::cout << "\n";
    }

    void PreOrderTraversal(Node *current)
    {
        bool firstCall = false;
        if (current == NULL)
        {
            firstCall = true;
            current = head;
        }
        // print current node
        std::cout << current -> val << " ";
        // check left node
        if (current->small)
            PreOrderTraversal(current->small);
        // check right node
        if (current->big)
            PreOrderTraversal(current->big);
        if (firstCall)
            std::cout << "\n";
    }
};


int main()
{
    BinaryTree b;
    //
    //              2
    //            /   \
    //          1       4
    //                /   \
    //              3       5
    //
    // In order: 1 - 2 - 3 - 4 - 5
    // Pre order: 2 - 1 - 4 - 3 - 5
    //
    b.Push(2);
    b.Push(4);
    b.Push(1);
    b.Push(5);
    b.Push(3);
    b.InOrderTraversal(NULL);
    b.PreOrderTraversal(NULL);
    return 0;
}
