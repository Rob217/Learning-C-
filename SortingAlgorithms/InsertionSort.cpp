#include <iostream>
#include <vector>

void printArray(std::vector<int> &arr)
{
    int len = static_cast<int>(arr.size());
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void insertionSort(std::vector<int> &arr)
{
    int len = static_cast<int>(arr.size());
    for (int i = 1; i < len; i++)
    {
        int j = i;
        do
        {
            std::cout << j << "\n";
            printArray(arr);
            if (arr[j] < arr[j-1])
                std::swap(arr[j], arr[j-1]);
            else
                break;
            j--;
        } while (j > 0);
    }
}

int main()
{
    std::vector<int> arr = {3,3,3,3,3,3};
    printArray(arr);
    insertionSort(arr);
    printArray(arr);

    return 0;
}
