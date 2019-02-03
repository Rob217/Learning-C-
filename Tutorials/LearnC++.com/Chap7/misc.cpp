#include <iostream>
#include <cassert>

void getInt(int i)
{
    assert(i>=0 && i<=9);

    std::cout << i << "\n";
}


int main()
{
    getInt(-3);
    return 0;
}

