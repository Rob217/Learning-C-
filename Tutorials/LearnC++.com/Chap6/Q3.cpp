#include <iostream>

void swapInts(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

int main()
{   
    int a, b;
    a = 3;
    b = 2;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    swapInts(a,b);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}
