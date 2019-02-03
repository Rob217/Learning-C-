#include <iostream>
#include <algorithm>

void doSomething(int *ptr)
{
    std::cout << ptr << "\n";
    std::cout << *ptr << "\n";
    for (int i = 0; i < 5; i++)
        std::cout << *(ptr+i) << "\n";

}

int main() 
{
    int arr[] = {5,2,6,1,3};
    doSomething(arr);

    return 0;
}
