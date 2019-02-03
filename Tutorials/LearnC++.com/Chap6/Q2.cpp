#include <iostream>
#include <string>
#include <algorithm>

struct Pupil
{
    std::string name;
    int grade;
};

void sortPupils(Pupil *pupilList, int nPupils)
{
    for (int i = 0; i < nPupils; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < nPupils; j++)
            {
                if (pupilList[j].grade < pupilList[minInd].grade)
                    minInd = j;
            }
        if (minInd != i)
            std::swap(pupilList[i], pupilList[minInd]);
    }
    
}

int main() 
{
    int nPupils;
    std::cout << "How many students do you want to enter? ";
    std::cin >> nPupils;

    Pupil pupilList[nPupils];
    for (int iPupil = 0; iPupil < nPupils; iPupil++)
    {
        std::cout << "Pupil name #" << iPupil + 1 << ": ";
        std::cin >> pupilList[iPupil].name;
        std::cout << pupilList[iPupil].name << "'s grade: ";
        std::cin >> pupilList[iPupil].grade;
    }

    sortPupils(pupilList, nPupils);

    for (int i = 0; i < nPupils; i++)
        std::cout << pupilList[i].name << " got " << pupilList[i].grade << "\n";

    return 0;
}
