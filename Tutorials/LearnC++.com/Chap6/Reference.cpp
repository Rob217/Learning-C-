#include <iostream>

void printArray(int (&arr)[5])
{
    for (auto i : arr)
        std::cout << i << "\n";
}

int main() 
{
    int arr[5] = {5,2,4,1,6};
    printArray(arr);
        
    return 0;
}
