#include <iostream>

enum Items
{
    HEALTH_POTIONS,
    TORCHES,
    ARROWS
};

int countTotalItems(int arr[3])
{
    int nItems = 0;
    nItems += arr[HEALTH_POTIONS] + arr[TORCHES] + arr[ARROWS];
    return nItems;
}

int main() 
{
    int items[3] = {2, 5, 10};
    int nItems;
    nItems = countTotalItems(items);
    std::cout << nItems << "\n";
    return 0;
}
