#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &vec);

void quickSort(std::vector<int> &vec, int lo, int hi)
{
    std::cout << "lo = " << lo << ", hi = " << hi << ", vec = ";
    print(vec);
    int i = lo;
    for (int j = lo; j < hi; j++)
    {
        if (vec[j] < vec[hi])
        {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }
    std::swap(vec[i], vec[hi]);
    print(vec);

    if (lo < i-1)
        quickSort(vec, lo, i-1);
    if (i+1 < hi)
        quickSort(vec, i+1, hi);
}

void print(std::vector<int> &vec)
{
    for (int i : vec)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> vec = {2};
    print(vec);
    std::cout << "... sort ...\n";
    int len = static_cast<int>(vec.size());
    quickSort(vec, 0, len-1);
    print(vec);

    return 0;
}

