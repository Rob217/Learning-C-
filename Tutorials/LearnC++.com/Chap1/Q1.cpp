#include <iostream>

int readNumber();
int writeNumber(int x, int y);


int main() 
{
	int x, y;
	x = readNumber();
	y = readNumber();
	writeNumber(x, y);

	return 0;
}