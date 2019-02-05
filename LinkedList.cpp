#include <iostream>

struct Node
{
    int val;
    Node *next = NULL;
};

class LinkedList
{
    Node *head, *tail;

public:
    LinkedList(): head {NULL}, tail {NULL}
    {
    }

    void add()
    {
        std::cout << "Please indicate a value to add to list\n";
    };

    void add(int val)
    {
        Node *temp = new Node;
        temp->val = val;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    int traverse()
    {
        if (checkNull(head))
            return 0;
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << "\n";
        return 0;
    }

    int deleteInd(int ind)
    {
        if (checkNull(head))
            return -1;

        Node *temp = head;
        int currentInd = 0;
        while (true)
        {
            // cases:
            // ind = 0 -> make next element head
            // 0 < ind < tail -> remove element
            // ind == tail -> replace tail
            // ind > tail -> do nothing
            
            if (ind == 0)
            {
                head = head->next;
                delete temp;
                temp = NULL;
                break;
            }

            if (temp->next == NULL)
            {
                std::cout << "Index must be within length of list! \n";
                return -1;
            }

            if (currentInd + 1 == ind)
            {
                Node *delPtr = temp->next;
                temp->next = delPtr->next;
                if (delPtr == tail)
                {
                    tail = temp;
                }
                delete delPtr;
                delPtr = NULL;
                break;
            }

            currentInd++;
            temp = temp->next;
        }
        return 0;
    }

    bool checkNull(Node *ptr)
    {
        if (ptr==NULL)
        {
            std::cout << "Length of list = 0\n";
            return true;
        }
        return false;
    }

};

int main()
{
    LinkedList l;
    l.traverse();
    l.add(2);
    l.traverse();
    l.add(3);
    l.traverse();
    l.add(4);
    l.traverse();
    l.deleteInd(0);
    l.traverse();
    l.deleteInd(1);
    l.traverse();
    l.add(5);
    l.add();
    l.traverse();

    return 0;
}
