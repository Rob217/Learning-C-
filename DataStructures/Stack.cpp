#include <iostream>

struct Stack
{
   Stack *ptr;
   int val;
};

bool isHead(Stack &a)
{
    if (a.ptr == NULL)
        return true;
    return false;
}

void push(Stack &a, int b)
{
    // add an element to the top of stack
    Stack *ptr = new Stack;
    ptr->val = a.val;
    ptr->ptr = a.ptr;
    a.ptr = ptr;
    a.val = b;
}

int pop(Stack &a)
{
    // take an element off the top of stack
    if (isHead(a))
        return 0;
    Stack *ptr = a.ptr;
    a.val = (*ptr).val;
    a.ptr = (*ptr).ptr;
    delete ptr;
    return 1;
}

void peek(Stack &a)
{
    // look at top element of stack
    std::cout << a.ptr << ", " << a.val << "\n";
}

int main()
{
    Stack a = {NULL, 10};
    peek(a);
    push(a, 3);
    peek(a);
    push(a, 4);
    peek(a);
    pop(a);
    peek(a);
    pop(a);
    peek(a);
    pop(a);
    peek(a);

    return 0;
}
