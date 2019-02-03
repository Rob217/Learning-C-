#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int> &arr)
{
    int len = static_cast<int>(arr.size());
    for (int i = 0; i < len; i++) 
    {
        int minInd = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minInd])
                minInd = j;
        }
        std::swap(arr[i], arr[minInd]);
    }
}

void printArray(std::vector<int> &arr)
{
    for (int i : arr)
        std::cout << i << "\n";
}

int main()
{
    std::vector<int> arr = {3, 2, 6, 4};
    selectionSort(arr);
    printArray(arr);
    return 0;
}
