#include <iostream>

struct Node 
{
    int val;
    Node *next = NULL;
    Node *prev = NULL;
};

class Queue
{
    Node *head, *tail;
public:
    Queue(): head {NULL}, tail {NULL}
    {
    }

    void enqueue(int val)
    {
        Node *temp = new Node;
        temp->val = val;

        if (tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->prev = temp;
            temp->next = tail;
            tail = temp;
        }
//        std::cout << "Head = " << head->val << ", " << head->prev << ", " << head->next << "\n";
//        std::cout << "Tail = " << tail->val << ", " << tail->prev << ", " << tail->next << "\n";
    }

    int dequeue()
    {
        if (head == NULL)
        {
            std::cout << "Cannot dequeue an empty queue\n";
            return -1;
        }
        int val = head->val;
        if (head->prev == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return val;
        }
        Node *temp = head->prev;
        temp->next = NULL;
        delete head;
        head = temp;
        return val;
    }

    void printHead()
    {
        if (head == NULL)
        {
            std::cout << "Cannot print head of an empty queue\n";
            return;
        }
        std::cout << head->val << "\n";
    }

};



int main()
{

    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.printHead();
    q.dequeue();
    q.printHead();
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.printHead();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();


    return 0;
}
