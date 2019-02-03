#include <iostream>
#include <vector>
#include <algorithm>

void printArray(std::vector<int> &arr, int len)
{
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void bubbleSort(std::vector<int> &arr, int len)
{
    bool swapping = true;
    while (swapping)
    {
        swapping = false;
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                std::swap(arr[i], arr[i+1]);
                swapping = true;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {5,1,2,6,3,6,2};
    int len = static_cast<int>(arr.size());
    printArray(arr, len);
    bubbleSort(arr, len);
    printArray(arr, len);
    return 0;
}
