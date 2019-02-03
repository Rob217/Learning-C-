#include <iostream>

class DateClass
{
    int m_year;
    int m_month;
    int m_day;

public:
    void setDate(int year = 2019, int month = 1, int day = 21)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    void print()
    {
        std::cout << m_day << "/" << m_month << "/" << m_year << "\n";
    }
};


int main() 
{
    DateClass today;
    today.setDate(2029, 2);
    today.print();
    return 0;
}
