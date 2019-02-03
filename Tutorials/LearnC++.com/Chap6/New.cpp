#include <iostream>

int main()
{
    int *ptr = new int[5] {5,2,6,3,1};

    delete[] ptr;

    ptr = NULL;



    return 0;
}
