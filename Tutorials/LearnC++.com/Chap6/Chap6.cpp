#include <iostream>
#include <string>

struct Marks 
{
	std::string name;
	int grade;
};

void orderMarks(Marks marks[], int numStudents)
{
	// selection sort
	for (int i = 0; i < numStudents - 1; i++) 
	{
		int minInd = i;
		for (int j = i + 1; j < numStudents; j++)
		{
			if (marks[j].grade < marks[minInd].grade)
				minInd = j;
		}
		std::cout << "i=" << i << " minInd=" << minInd << "\n";
		std::swap(marks[i], marks[minInd]);
	}
}

void printMarks(Marks marks[], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
		std::cout << marks[i].name << " got a grade of " << marks[i].grade << "\n";
}

int main() 
{
	int numStudents;
	std::cout << "How many students do you want to enter? ";
	std::cin >> numStudents;

	Marks *studentMarks = new Marks[numStudents];

	for (int i = 0; i < numStudents; i++)
	{
		std::cout << "Name #" << i + 1 << ": ";
		std::cin >> studentMarks[i].name;
		std::cout << "Mark: ";
		std::cin >> studentMarks[i].grade;
	}

	orderMarks(studentMarks, numStudents);

	printMarks(studentMarks, numStudents);

	delete[] studentMarks;

	return 0;
}