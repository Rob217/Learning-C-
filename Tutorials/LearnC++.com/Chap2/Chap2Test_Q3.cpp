// https://www.learncpp.com/cpp-tutorial/210-comprehensive-quiz/

#include <iostream>


double getDouble() 
{
	double x;
	std::cout << "Enter a double value: ";
	std::cin >> x;
	return x;
}


int main() 
{
	double x, y;
	x = getDouble();
	y = getDouble();

	char op;
	std::cout << "Enter one of the following: +, -, *, oir /: ";
	std::cin >> op;

	std::cout << x << op << y << "=";
	double out;
	if (op == '+')
		out = x + y;
	else if (op == '-') 
		out = x - y;
	else if (op == '*')
		out = x * y;
	else if (op == '/')
		out = x / y;
	std::cout << out << std::endl;

	return 0;
}