#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double d;
    std::cin >> d;
    return d;
}

char getSymbol()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op;
    std::cin >> op;
    return op;
}

void printAnswer(double a, double b, char op)
{
    double ans;
    if (op == '+')
        ans = a + b;
    else if (op == '-')
        ans = a - b;
    else if (op == '*')
        ans = a * b;
    else if (op == '/')
        ans = a / b;
    else 
        return; 

    std::cout << a << " " << op << " " << b << " = " << ans << std::endl;
}

int main()
{
    double d, e;
    d = getDouble();
    e = getDouble();
    char op;
    op = getSymbol();
    printAnswer(d, e, op);

    return 0;
}
