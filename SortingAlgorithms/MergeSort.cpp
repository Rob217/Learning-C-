#include <iostream>
#include <vector>

void printArr(std::vector<int> &arr, int lo, int hi)
{
    for (int i = lo; i <= hi; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}   

void mergeSort(std::vector<int> &arr, int lo, int hi)
{
    if (lo != hi)
    {
        int mid = (hi - lo) / 2 + lo;
        std::vector<int> arrL;
        std::vector<int> arrR;
        int lenL = (mid - lo) + 1;
        int lenR = (hi - mid);
        arrL.resize(lenL);
        arrR.resize(lenR);
        int l = 0;
        int r = 0;
        for (int i = lo; i <= mid; i++)
        {
            arrL[l] = arr[i];
            l++;
        }
        for (int j = mid + 1; j <= hi; j++)
        {
            arrR[r] = arr[j];
            r++;
        }

        // could get rid of lo and hi and just call it 0 and len-1
        mergeSort(arrL, 0, lenL - 1);
        mergeSort(arrR, 0, lenR - 1);

        // now merge
        l = 0;
        r = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (l >= lenL)
            {
                arr[i] = arrR[r];
                r++;
            }
            else if (r >= lenR)
            {
                arr[i] = arrL[l];
                l++;
            }
            else if (arrR[r] > arrL[l])
            {
                arr[i] = arrL[l];
                l++;
            }
            else
            {
                arr[i] = arrR[r];
                r++;
            }
        }
    }
}

int main() 
{
    std::vector<int> arr = {5,2,6,3,1,1};
    int len = static_cast<int>(arr.size());
    printArr(arr, 0, len - 1);
    mergeSort(arr, 0, len - 1);
    printArr(arr, 0, len - 1);

    return 0;
}
